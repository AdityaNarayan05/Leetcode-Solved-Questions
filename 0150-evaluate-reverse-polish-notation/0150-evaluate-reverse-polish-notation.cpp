using func = std::function<long(long, long)>;
auto const dispatcher = std::unordered_map<std::string, func> {
    {"+"s, std::plus()},
    {"-"s, std::minus()},
    {"/"s, std::divides()},
    {"*"s, std::multiplies()}
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        auto stk = std::stack<long>();
            for(auto const token : tokens) {
            if(!dispatcher.count(token)) {
                stk.push(stoi(token));
                continue;
            }

            auto const num1 = stk.top(); stk.pop();
            auto const num2 = stk.top(); stk.pop();
            stk.push(dispatcher.at(token)(num2, num1));

        }
        return stk.top();
    }
};