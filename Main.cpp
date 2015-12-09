#include "String.h"

#include <stdexcept>
#include "assert.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    String s0;          assert(s0 == "");
    String s1("foo");   assert(s1 == "foo");
    String s2(s1);      assert(s2 == "foo");
    String s3("bar");   assert(s3 == "bar");
    
    delete new String("hej");
    
    assert((s2 = s3) == s3);
    assert((s2 = s2) == s3);
    
    assert((s2 = "foo") == "foo");
    assert((s2 = "bar") == "bar");
    
    (s2 += s1) += (s3 += s1);
    assert(s3 == "barfoo" && s2 == "barfoobarfoo" && s1 == "foo");
    
    s2 = "bar";
    assert(s1 + s2 == "foobar" && s1 == "foo");
    
    try {
        s2.at(-1);
    } catch (out_of_range& e) {
        assert(true);
    }
    try {
        s2.at(2);
    } catch (out_of_range& e) {
        assert(false);
    }
    assert(s2.at(2) = 'r');
    
    s2[-1];
    s2[1000];
    assert(s2[1] == 'a');
    
    s2.push_back('a');
    assert(s2 == "bara");
    
    s2.shrink_to_fit();
    assert(s2.length() == s2.capacity());
    
    const char* p1 = s2.data();
    assert(p1 == s2.data());
   
    String s4(s2.data());
    s2.shrink_to_fit();
    
    assert(s4 == s2.data());

    
    
    String h("abcdefgh");
    
    cout << h.data() << endl;
    
    //const char* gg = h.data();
    
    //cout << gg << endl;
    
    String g("abcde");
    
    String j(g.data());
    
    cout << j << endl;
    
    //cout << h[0] << endl;
    cout << h.length() << endl;
    
    cout << h.at(2) << endl;
    //cout << h.at(17) << endl;
    //cout << h.at(18) << endl;
    
    String z("julian");
    
    cout << z << endl;
    
    cout << z.data() << endl;
    
    z = h;
    
    cout << z << endl;
    
    cout << h << endl;
    
    //cout << "Testing += String assignment" << endl;
    
    String q("testing");
    String r("my name");
    
    q += r;
    
    //testingmy name
    cout << q << endl;
    
    cout << q.data() << endl;
    
    //testingmy nam[e]
    cout << q.at(13) << endl;
    
    String aa("aa");
    String bb("bb");
    
    String dd(aa);
    
    cout << dd << endl;
    
    dd = dd;
    
    cout << dd << endl;
    
    bb.data();
    
    String cc = aa;
    aa = bb;
    
    cout << cc << endl;
    
    cc.push_back('b');
    cout << cc << endl;
    cc.push_back('b');
    cc.push_back('c');
    cout << cc << endl;
    
    cout << cc.capacity() << endl;
    cc.shrink_to_fit();
    cout << cc << endl;
    cout << cc.capacity() << endl;
    
    String eq1("abc");
    String eq2("abc");
    
    bool b1 = (eq1 == eq2);
    cout << b1 << endl;
    
    String s = (eq1 + eq2);
    
    // abcabc
    cout << s << endl;
    
    String eq3("");
    String eq4("0");
   
    bool b2 = (eq3 == eq4);
    cout << b2 << endl;
    
    String c;
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    c.push_back('q');
    
    // qqqqqqqq
    cout << c << endl;
    
    //cout << "Char test" << endl;
    
    String qq;
    qq = "abc";
    
    cout << qq << endl;
    
    String vv("qq)");
    vv = 'b';
    
    // b
    cout << vv << endl;
    
    String yy("c");
    yy += "bb";
    
    // ababb
    cout << yy << endl;
    
    return 0;
}
