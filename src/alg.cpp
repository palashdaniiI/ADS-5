// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int expr(char nu, int a, int b) {
  switch (nu) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
  }
  return 0;
}

int advan(char nu) {
  switch (nu) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default: return 4;
  }
}

std::string infx2pstfx(std::string inf) {
std::string res;
  char whit = ' ';
  TStack <char, 100> res_st1;
  for (int i = 0; i < inf.size(); i++) {
    if (advan(inf[i]) == 4) {
      res.move(inf[i]);
      res.move(whit);
    } else {
      if (advan(inf[i]) == 0) {
        res_st1.push(inf[i]);
      } else if (res_st1.isEmpty()) {
          res_st1.push(inf[i]);
      } else if ((advan(inf[i]) > advan(res_st1.get()))) {
          res_st1.push(inf[i]);
      } else if (advan(inf[i]) == 1) {
        while (advan(res_st1.get()) != 0) {
          res.move(res_st1.get());
          res.move(whit);
          res_st1.pop();
        }
        res_st1.pop();
      } else {
        while ((advan(inf[i]) <= advan(res_st1.get()))&&(!res_st1.isEmpty())) {
        char a = advan(inf[i]);
        char b = advan(res_st1.get());
        while ((a <= b) && (!res_st1.isEmpty())) {
          res.move(res_st1.get());
          res.move(whit);
          res_st1.pop();
        }
        res_st1.push(inf[i]);
      }
    }
  }
  while (!res_st1.isEmpty()) {
    res.move(stack.get());
    res.move(whit);
    stack.pop();
  }
  for (int i = 0; i < res.size(); i++) {
    if (res[res.size() - 1] == ' ')
      res.erase(res.size() - 1);
  }
  return res;
}

int eval(std::string con) {
  TStack <int, 100> res_st2;
    int res = 0;
    for (int i = 0; i < con.size(); i++) {
        if (advan(con[i]) == 4) {
            res_st2.push(con[i] - '0');
        } else if (advan(con[i]) < 4) {
            int a = res_st2.get();
            res_st2.pop();
            int b = res_st2.get();
            res_st2.pop();
            res_st2.push(expr(con[i], a, b));
        }
    }
    res = res_st2.get();
    return res;
}
