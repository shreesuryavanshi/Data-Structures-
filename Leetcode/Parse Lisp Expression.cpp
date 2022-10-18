class Solution {
    vector<string_view> parse(string_view expr) {
        int cursor = 1, start = 1;
        vector<string_view> tokens;
        while (cursor < expr.length()) {
            if (expr[cursor] == ' ' || expr[cursor] == ')') {
                tokens.emplace_back(expr.substr(start, (cursor - start)));
                start = cursor + 1;
            } else if (expr[cursor] == '(') {
                int open_parenthesis = 1;
                while (open_parenthesis) {
                    ++cursor;
                    if (expr[cursor] == '(') ++open_parenthesis;
                    else if (expr[cursor] == ')') --open_parenthesis;
                }
            }
            ++cursor;
        }

        return tokens;
    }

    int evaluate(vector<string_view> &tokens, unordered_map<string_view, int> variables) {
        int return_val;
        if (tokens[0] == "mult")
            return_val = getVal(tokens[1], variables) * getVal(tokens[2], variables);
        else if (tokens[0] == "add")
            return_val = getVal(tokens[1], variables) + getVal(tokens[2], variables);
        else {
            for (int i = 1; i < tokens.size() - 1; i += 2)
                variables[tokens[i]] = getVal(tokens[i + 1], variables);
            return getVal(tokens.back(), variables);
        }

        return return_val;
    }

    int getVal(string_view expr, unordered_map<string_view, int> &variables) {
        int type = getType(expr);
        if (type == 1) {
            vector<string_view> tokens = parse(expr);
            return evaluate(tokens, variables);
        } else if (type == 2) return variables[expr];
        int val = 0, sign = 1;
        for (auto &c: expr)
            if (c == '-') sign = -1;
            else val = (val * 10) + (c - '0');
        return val * sign;
    }

    int getType(string_view expr) {
        return (expr[0] == '(') ? 1 : (expr[0] >= 'a' && expr[0] <= 'z') ? 2 : 3;
    }

public:
    int evaluate(string expression) {
        unordered_map<string_view, int> variables;
        return getVal(string_view(expression), variables);
    }
};
