// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    A = A + '/'; // '/' is added so that complete string will be processed in loop only
    vector<string> list;
    string currString = "";
    for (auto a: A) {
        if (a == '/') {
            if (currString.size() > 0 && currString != "." && currString != "..")
                list.push_back(currString);
            if (currString == ".." && !list.empty())
                list.pop_back();
            currString.clear();
        } else currString += a;
    }
    
    if (list.empty()) return "/";
    string retString = "";
    for (auto l: list) retString += "/" + l;
    return retString;
}