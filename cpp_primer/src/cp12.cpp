#include "cp12.hpp"
#include <vector>
#include <memory>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

class strBlobPtr;
class strBlob
{
public:
    friend class strBlobPtr;
    strBlobPtr begin();
    strBlobPtr end();

    strBlob() : data(std::make_shared<std::vector<string>> ()) {};
    strBlob(std::initializer_list<string> il) : data(std::make_shared<std::vector<string>>(il)) {};
    strBlob &push_back(const string &s) { data->push_back(s); return *this; }
    //const strBlob &push_back(const string &s) const { data->push_back(s); return *this; }

    void print()
    {
        for (auto s : *data) {
            cout << s << " ";
        }
        cout << endl;
    };
    const string &front(void) { return data->front(); }
    const string &back(void) { return data->back(); }

private:
    std::shared_ptr<std::vector<string>> data;
};

class strBlobPtr
{
public:
    strBlobPtr(strBlob &b, size_t sz = 0) : wptr(b.data), curr(sz) {}
    strBlobPtr() {}

    void assign(strBlob &b) { wptr = b.data; }
    string &deref() const
    {
        auto p = check(curr, "deference pass end");
        return (*p)[curr];
    }
    strBlobPtr &incr()
    {
        check(curr, "increament past end of strBlobPtr");
        ++curr;
        return *this;
    }
    bool operator!=(const strBlobPtr& p) { return p.curr != curr; }

private:
    std::shared_ptr<std::vector<string>> check(size_t sz, const string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound strBlobPtr");
        }
        if (sz >= ret->size()) {
            throw std::out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<std::vector<string>> wptr;
    size_t curr = 0;
};

strBlobPtr strBlob::begin() { return strBlobPtr(*this); }
strBlobPtr strBlob::end() { return strBlobPtr(*this, data->size()); }

std::vector<int> *new_vector()
{
    return new std::vector<int>;
}

std::shared_ptr<std::vector<int>> make_shared_vector()
{
    return std::make_shared<std::vector<int>>();
}

void fill_vector(std::vector<int> *p)
{
    int n = 0;
    cout << "This is new, enter some numbers:" << endl;
    cin.clear();
    while (cin >> n) {
        p->push_back(n);
    }

    for (auto i : *p) {
        cout << i << " ";
    }
    cout << endl;
}

void fill_vector(std::shared_ptr<std::vector<int>> p)
{
    int n = 0;
    cout << "This is share pointer, enter some numbers:" << endl;
    cin.clear();
    while (cin >> n) {
        p->push_back(n);
    }

    for (auto i : *p) {
        cout << i << " ";
    }
    cout << endl;
}

class fd
{
public:
    fd() {};
    ~fd() {};

    void connect() { ++fs_ref; cout << "connect " << fs_ref << endl; };
    void disconnect() { if (fs_ref > 0) --fs_ref; cout << "disconnect " << fs_ref << endl; };

private:
    static int fs_ref;
};
int fd::fs_ref = 0;

void disconn(fd * p)
{
    p->disconnect();
}

void ex_12_14_15(void)
{
    fd my_fd;
    std::shared_ptr<fd> pfd(&my_fd, disconn);
    //std::shared_ptr<fd> pfd(&my_fd, [](fd * p) { p->disconnect(); });

    pfd->connect();
    cout << "End of ex_12_14" << endl;
}
void ex12_1(void)
{
    // 12.1 - 12.5
    //strBlob sb({ "a", "an" });
    //sb.push_back("im qmz");
    //sb.print();
    //cout << sb.front() << " " << endl;
    //cout << sb.back() << " " << endl;

    //const strBlob csb({ "aa", "aan" });
    ////csb.push_back("xyz");

    // 12.6, 12.7
    //std::vector<int> *p_vec = new_vector();
    //std::shared_ptr<std::vector<int>> p_share_vec = make_shared_vector();

    //fill_vector(p_vec);
    //fill_vector(p_share_vec);
    //delete p_vec;
    //p_vec = NULL;

    // 12.8
    /* return pointer for bool, error */

    // 12.9
    /* old r will cause memoty leakage */
    /* old r2 will be released automatically */

    // 12.10
    /* Correct */

    // 12.11
    /* An error was generated at run time: double free prossibility cause corruption */

    // 12.12
    /*
    	a. correct
    	b. illegal, plant pointer can't convert to shared_ptr implicity
    	c. illegal, plant pointer can't convert to shared_ptr implicity
    	d. runtime error
    */

    // 12.13
    /* Runtime error, double free */

    // 12.14 12.15
    //ex_12_14_15();

    // 12.16
    std::unique_ptr<int> up_int(new int(12));
    //std::unique_ptr<int> up_int1(up_int);

    // 12.17
    /*
    	compile error: p0
    	recomented  : p4(new int(2048));
    	run time error :
    		p1/p3: pi/&ix is not allocate using new
    		p2: Will cause a dangling pointer at run time
    		p5: one of p2/p5 if free the pointer will cause another unique_ptr reference invalid pointer
    		p6: Double free or courruption on run time
    */

    // 12.18
    /* Cause multi-shared_ptr don't need release when copy/assigment/reference */
}

class dynamicArray
{
public:
    dynamicArray(uint16_t sz = 20) : totol(sz), curr(0), p(new char[sz]) {};
    ~dynamicArray() { delete[] p; };
    dynamicArray &push(const char *sc, uint16_t len)
    {
        if (curr + len > totol) {
            totol = 2 * totol;
            char *p_new = new char[totol] {};

            strcpy_s(p_new, totol, p);
            strcat_s(p_new, totol, sc);
            delete[] p;
            p = p_new;
            curr += len;
        } else {
            if (curr == 0) {
                strcpy_s(p, totol, sc);
            } else {
                strcat_s(p, totol, sc);
            }
            curr += len;
        }
        return *this;
    }
    void print()
    {
        cout << p << endl;
    }

private:
    char *p;
    uint16_t totol;
    uint16_t curr;
};

class fileSearcher
{
public:
    fileSearcher(std::ifstream &in_f);
    ~fileSearcher() {};
    bool find(const string &word);

private:
    int find_in_result(const string &word);
    std::vector<string> text;
    std::map<string, std::vector<int>> words_map;
};

class QueryResult;
class TextQuery
{
public:
    using LineNo_t = std::vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;

private:
    std::shared_ptr<std::vector<string>> input;
    std::map<string, std::shared_ptr<std::set<LineNo_t>>> result;
};

TextQuery::TextQuery(std::ifstream &ifs) : input(new std::vector<string>)
{
    LineNo_t lno = 0;

    for (string line; ifs >> line; ++lno) {
        input->push_back(line);
        std::istringstream iss(line);
        for (string text; iss >> text; ) {
            string word;
            // avoid read a word followed by punctuation(such as: word, )
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto &nos = result[word];
            if (!nos)
                nos.reset(new std::set<LineNo_t>);
            nos->insert(lno);
        }
    }

}

class QueryResult
{
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, std::shared_ptr<std::set<TextQuery::LineNo_t>> set, std::shared_ptr<std::vector<string>> v) : word(s), nos(set), input(v) { }
private:
    string word;
    std::shared_ptr<std::set<TextQuery::LineNo_t>> nos;
    std::shared_ptr<std::vector<string>> input;
};

fileSearcher::fileSearcher(std::ifstream &in_f)
{
    string line;
    /* Load file */
    while (std::getline(in_f, line)) {
        text.push_back(line);
    }
}

int fileSearcher::find_in_result(const string &word)
{

    auto search = words_map.find(word);

    if (search != words_map.end()) {
        if (search->second[0] < 0) {
            cout << "No [" << word << "] find" << endl;
            return -1;
        }

        cout << search->second.size() << " \"" << word << "\" find" << endl;
        for (auto it = search->second.begin(), end = search->second.end(); it != end; ++it) {
            std::cout << "L" << *it + 1 << ":" << text[*it] << endl;
        }
        return search->second.size();
    }
    return 0;
}

bool fileSearcher::find(const string &word)
{
    int ret = find_in_result(word);

    if (ret != 0) {
        return ret > 0;
    } else { /* go through text */
        int line_cnt = 0;
        bool found = false;
        for (auto it = text.cbegin(), end = text.cend(); it != end; ++it) {
            std::istringstream iss(*it);
            std::set<string> str_set;
            string word_in_text;

            while (iss >> word_in_text) {
                string word_strip;
                // avoid read a word followed by punctuation(such as: word, )
                std::remove_copy_if(word_in_text.begin(), word_in_text.end(), std::back_inserter(word_strip), ispunct);
                str_set.insert(word_strip);
            }
            if (str_set.end() != str_set.find(word)) {
                words_map[word].push_back(line_cnt);
                found = true;
            }
            ++line_cnt;
        }
        if (found == false) {
            cout << "No \"" << word << "\" found" << endl;
            words_map[word].push_back(-1);// mark, as no this word
            return false;
        }
    }
    return find_in_result(word);
}

QueryResult TextQuery::query(const string& str) const
{
    // use static just allocate once.
    static std::shared_ptr<std::set<LineNo_t>> nodata(new std::set<LineNo_t>);
    auto found = result.find(str);
    if (found == result.end()) return QueryResult(str, nodata, input);
    else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
    return out;
}

void ex12_2(void)
{
    // 12.19
    //strBlobPtr sbp;
    //{
    //	strBlob sb = { "a", "an", "sb" };
    //	sbp.assign(sb);
    //}
    //while (1) {
    //	cout << sbp.deref() << endl;
    //	sbp.incr();
    //}

    // 12.20
    //strBlob sb;
    //string line;
    //std::ifstream ifs("../data/ex12_20.txt");

    //while (std::getline(ifs, line)) {
    //	sb.push_back(line);
    //}
    //strBlobPtr sbp(sb);
    //while (1) {
    //	cout << sbp.deref() << endl;
    //	sbp.incr();
    //}

    // 12.21
    /* Original style is more readable */

    // 12.22
    //strBlob sb;
    //string line;
    //std::ifstream ifs("../data/ex12_20.txt");

    //while (std::getline(ifs, line)) {
    //	sb.push_back(line);
    //}
    //strBlobPtr sbp(sb);
    //for (strBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg != pend; pbeg.incr()) {
    //	cout << pbeg.deref() << endl;
    //}

    // 12.23
    //const char* cs1 = "cstring1";
    //const char* cs2 = "cstring2";
    //char *p = (char *)new char[strlen(cs1) + strlen(cs2) + 1] {0};

    //memcpy(p, cs1, strlen(cs1));
    //memcpy(p + strlen(cs1), cs2, strlen(cs2));
    //cout << p << endl;
    //delete [] p;

    //string s1 = "string1";
    //string s2 = "string2";
    //cout << s1 + s2 << endl;

    // 12.24
    //dynamicArray dArray;
    //string s;
    //cout << "Enter some characters" << endl;
    //while (cin >> s) {
    //	dArray.push(s.c_str(), s.size());
    //}
    //dArray.print();

    // 12.25
    // delete [] p;

    // 12.26
    //std::allocator<string> str_alloc;
    //auto p = str_alloc.allocate(5);
    //auto q = p;
    //string s;

    //while (p +5 != q && cin >> s) {
    //	str_alloc.construct(q++, s);
    //}
    //while (q != p) {
    //	cout << *--q << endl;
    //	str_alloc.destroy(q);
    //}
    //str_alloc.deallocate(p, 5);

    // 12.27, 12.28, 12.29
    //std::ifstream in_file("../data/ex12_27.txt");
    //fileSearcher fser(in_file);
    //string word;

    //cout << "Enter word to find" << endl;
    //while (cin >> word) {
    //    fser.find(word);
    //}
    std::ifstream in_file("../data/ex12_27.txt");
    TextQuery tq(in_file);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

void cp12_loop(void)
{
    cout << "Welcom to cp12" << endl;

    //ex12_1();

    try {
        ex12_2();
    } catch (const std::exception & ex) {
        std::cerr << ex.what() << endl;
    }
}