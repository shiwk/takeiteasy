//
// Created by swk on 2019-08-23.
//

#include "stringmatch.h"

namespace happycoding {
    class BfMatch : public StringMatch{
    public:
        int indexOf (const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize) override{
            for (unsigned int i = 0; i < textSize - patternSize + 1; ++i) {
                bool isMatched = true;
                for (unsigned int j = 0; j < patternSize; ++j) {
                    if (text[i + j] != pattern[j])
                    {
                        isMatched = false;
                        break;
                    }
                }
                if (isMatched)
                    return i;
            }
            return -1;
        }
    };
}