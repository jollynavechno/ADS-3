// Copyright 2021 NNTU-CS
#include <iostream>
#include "tstack.h"

int Priority(char c) {
if (c == '*' || c == '/') {
return 2;
} else {
if (c == '+' || c == '-') {
return 1;
} else {
return 0;
}
}
}
std::string infx2pstfx(std::string inf) {
TStack<char> cstack;
std::string pst;
for (int i = 0; i < inf.length(); ++i) {
if ((inf[i] >= '0') && (inf[i] <= '9')) {
pst += inf[i];
pst += ' ';
} else if ((inf[i] == '(') || (cstack.isEmpty()) || (Priority(inf[i]) > Priority(cstack.get()))) {
cstack.push(inf[i]);
} else if (inf[i] == ')') {
char ch = cstack.get();
cstack.pop();
while (ch != '(') {
pst += ch;
pst += ' ';
ch = cstack.get();
cstack.pop();
}
} else {
while (!cstack.isEmpty() && (Priority(cstack.get()) >= Priority(inf[i]))) {
pst += cstack.get();
pst += ' ';
cstack.pop();
}
cstack.push(inf[i]);
}
}
while (!cstack.isEmpty()) {
pst += cstack.get();
pst += ' ';
cstack.pop();
}
pst.pop_back();
return pst;
}
int eval(std::string pst) {
TStack<int> istack;
for (int i = 0; i < pst.length(); i++) {
if (pst[i] >= '0' && pst[i] <= '9')
istack.push(pst[i] - '0');
else if (pst[i] != ' ') {
int var1 = istack.get();
istack.pop();
int var2 = istack.get();
istack.pop();
if (pst[i] == '*')
istack.push(var2 * var1);
else if (pst[i] == '/')
istack.push(var2 / var1);
else if (pst[i] == '+')
istack.push(var2 + var1);
else
istack.push(var2 - var1);
}
}
return istack.get();
}
