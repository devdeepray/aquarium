#include <simplecpp>
#include "textbox.h"
void textbox::newtext(string a) {//add new text to text box.
  if(a == s1) return;//if new text is first statement, do nothing.
  if(a == s2) {//if it is second , bring it to the top.
      s2 = s1;
      s1 = a;
    }
  else {//if it is third, bring it to the top. also works if not present in the text box.
      s3 = s2;
      s2 = s1;
      s1 = a;
    }
  Rectangle r(400, 650, 700, 90);//clear the box.
  r.setFill(true);
  r.setColor(COLOR("white"));
  r.imprint();
  t.init(400, 630, s1);//show text 1.
  t.imprint();
  t.init(400, 650, s2);//show text 2.
  t.imprint();
  t.init(400, 670, s3);//show text 3.
  t.imprint();
}
