#include <iostream>
#include <vector>
#include <unordered_map>

class IntToEng {
public:
    std::vector<std::pair<int, std::string>> Words = {
{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
{11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
{100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};

std::unordered_map<int, std::string> Lists = {
{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
{11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
{100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};

std::vector<std::string> NumToEng(int num) {
    int i = 30;
    std::vector<std::string> ans;
    while(num && i >= 0) {
        int x = num / Words[i].first;
        if(Lists.find(x) != Lists.end() && i >= 27) ans.push_back(Lists[x]);
        else if(Lists.find(x) == Lists.end()) {
            std::vector<std::string> result = NumToEng(x);
            ans.insert(ans.end(), result.begin(), result.end());
        }

        if(x > 0) ans.push_back(Words[i].second);
        num %= Words[i].first;
        i--;
    }
    return ans;
}

    std::string numberToWords(int num) {
        if(num == 0) return "Zero";
        std::string result;
        std::vector<std::string> ans = NumToEng(num);
        if(ans[0] == "Hundred") result += "One ";
        for(std::string s : ans) {
            result += s;
            result += ' ';
        }
        result.pop_back();
        return result;
    }
};

int main() {
    IntToEng *Huy = new IntToEng;
    int num; std::cin >> num;
    std::cout << Huy -> numberToWords(num);

    return 0;
}
