#pragma once
#include <unordered_map>
#include <vector>
#include <string>
class AAnalyser {
    protected:
    std::unordered_map<std::string, int> _strMap;
    std::vector<bool> _massRes;


    public:
    virtual void checkManyString(std::vector<std::string> &)=0;
    [[nodiscard]] const std::vector<bool> & getMassResult() const {return _massRes;};
    [[nodiscard]] const std::unordered_map<std::string, int> & getStateMap() const {return _strMap;};

    virtual ~AAnalyser()= default;

};
