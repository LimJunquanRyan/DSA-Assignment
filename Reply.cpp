#include <string>
#include <iostream>
#include "Reply.h"


Reply::Reply() { }

Reply::Reply(string t, string d) : ForumElements(t, d) { }

void Reply::print() { ForumElements::print(); }