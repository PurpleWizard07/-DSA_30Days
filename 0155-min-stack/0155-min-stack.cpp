class MinStack {
private:
    std::stack<long long> s;
    long long minVal;

public:
    MinStack() {
        minVal = LLONG_MAX;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        long long top = s.top();
        if (top < minVal) {
            minVal = 2LL * minVal - top;
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;

        long long top = s.top();
        if (top < minVal) {
            return minVal;
        }
        return top;
    }

    int getMin() {
        if (s.empty()) return -1;
        return minVal;
    }
};
