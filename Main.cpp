#include "String.h"

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //String s("hello");
    //cout << s.length() << endl;
    
    //cout << s.at(4) << endl;
    
    //String q("abcdefgh ijklmnopq");
    
    //cout << q.length() << endl;
    
    String h("abcdefgh");
    
    cout << h << endl;
    
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
    
    cout << "Testing += String assignment" << endl;
    
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
    
    String cc = aa;
    aa = bb;
    
    bb.data();
    
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
