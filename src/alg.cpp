// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
#include "tstack.h"

int expr(char nu, int a, int b) {
  switch (nu) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
      if (a != 0)
      return b / a;
  default: return 0;
  }
  return 0;
}

int advan(char nu) {
  switch (nu) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
  }
  return 0;
}

bool requ(std::string con, char nu) {
  for (int i = 0; i < con.length(); ++i) {
    if (con[i] == nu) {
      return true;
    }
  }
  return false;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack;
  std::stack<char> Stack;
  std::string num = "0123456789";
  std::string operat = "()+-*/";
  std::string result = "";
  for (int i = 0; i < inf.length(); ++i) {
    if (requ(num, inf[i])) {
      result += inf[i];
      result += ' ';
    } else if (requ(operat, inf[i])) {
      if (advan(inf[i]) == 0) {
        Stack.push(inf[i]);
      } else if (Stack.empty()) {
        Stack.push(inf[i]);
      } else if (advan(inf[i]) > advan(Stack.top())) {
        Stack.push(inf[i]);
      } else if (inf[i] == ')') {
        while (Stack.top() != '(') {
          result += Stack.top();
          result += ' ';
          Stack.pop();
        }
        if (Stack.top() == '(') {
          Stack.pop();
        }
      } else {
        for (int j = 0; j<= Stack.size(); ++j) {
          if (advan(Stack.top()) >= advan(inf[i])) {
            result += Stack.top();
            result += ' ';
            Stack.pop();
          }
        }
        Stack.push(inf[i]);
      }
    }
  }
  if (!Stack.empty()) {
    for (int j = 0; j <= Stack.size(); ++j) {
      result += Stack.top();
      result += ' ';
      Stack.pop();
    }
  }
  if (result[result.length() - 1] == ' ') {
    result.erase(result.length() - 1);
  }
  return result;
}

int eval(std::string pref) {
  int sum = 0;
  std::stack<int> Stack;
  TStack<int, 100> stack;
  std::string num = "0123456789";
  std::string operat = "()+-*/";
  for (int i = 0; i < pref.length(); ++i) {
    if (requ(num, pref[i])) {
      Stack.push(pref[i] - '0');
    } else if (requ(operat, pref[i])) {
      int a = 0, b = 0;
      a = Stack.top();
      Stack.pop();
      b = Stack.top();
      Stack.pop();
      if (pref[i] == '+') {
        Stack.push(b + a);
      }
      if (pref[i] == '-') {
        Stack.push(b - a);
      }
      if (pref[i] == '*') {
        Stack.push(b * a);
      }
      if (pref[i] == '/') {
        Stack.push(b / a);
      }
    }
  }
  sum = Stack.top();
  return sum;
}
