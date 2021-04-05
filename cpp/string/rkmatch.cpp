//
// Created by swk on 2019-08-24.
//

#include <cmath>
#include "stringmatch.h"

namespace happycoding{
    class RkMatch : public StringMatch{
    public:
        int indexOf(const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize) override{
            if (textSize < patternSize)
                return -1;
            unsigned long long h = hash(pattern, 0, patternSize);
            for (unsigned int i = 0; i < textSize - patternSize + 1; ++i) {
                if (hash(text, i, i     + patternSize) == h)
                {
                    bool isMatched = true;
                    for (unsigned int j = 0; j < patternSize; ++j) {
                        if(text[i + j] != pattern[j])
                        {
                            isMatched = false;
                            break;
                        }
                    }
                    if(isMatched)
                        return i;
                }
            }
            return -1;
        }

    private:
        unsigned long long hash(const char * chars, unsigned int start, unsigned int end) const{
            unsigned long long res = 0;
            int primes[10] = {2,3,5,7,11,13,17,19,23,29};
            for (unsigned int i = start; i < end; ++i) {
                    char c = chars[i];
                    int g = c - 40;
                    int prime = primes[g%10];
                    res += static_cast<unsigned long long>(pow(g, 2)) * prime;
            }
            return res;
        }
    };
}