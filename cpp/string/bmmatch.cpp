//
// Created by swk on 2019-09-03.
//

#include "stringmatch.h"
#include <algorithm>
namespace happycoding{
    class BmMatch : public StringMatch{
    public:
        int indexOf(const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize) override {
            if(textSize < patternSize || patternSize == 0)
                return -1;

            int positions[128];
            for (int & j : positions) {
                j = -1;
            }
            for (int i = 0; i < patternSize ; ++i) {
                unsigned int index = pattern[i];
                positions[index]  = i;
            }

            int suffix[patternSize + 1];
            bool prefix[patternSize + 1];
            for (int & j : suffix)
            {
                j = -1;
            }

            for (int l = 1; l <= patternSize; ++l) {
                for (int i = 0 ; i < patternSize - l ; ++i) {
                    bool isMatched = false;
                    for (int j = 0; j < l; ++j) {
                        if(pattern[i+j] != pattern[patternSize - l + j]){
                            isMatched = false;
                            break;
                        }
                        isMatched = true;
                    }

                    if (isMatched) {
                        suffix[l] = i;
//                        std::cout<< "suffix["<<l<<"] = "<< suffix[l]<<std::endl;
                        if (i == 0)
                        {
                            prefix[l] = true;
//                            std::cout<< "prefix["<<l<<"] = "<< prefix[l]<<std::endl;
                        }
                    }
                }
            }

            for (unsigned int k = 0; k < textSize - patternSize + 1;) {
                bool isMatched = true;
                int i = patternSize - 1;
                while (i >= 0) {
                    if (text[k + i] != pattern[i])
                    {
                        isMatched = false;
                        break;
                    }

                    i--;
                }
                if (!isMatched)
                {
                    int position = positions[text[k + i]];
                    int offset1 = i - position;

                    int offset2 = 1;
                    int l = patternSize - 1 - i;
                    {
                        int suffixMatchingPosition = suffix[l];
                        if(suffixMatchingPosition != -1)
                        {
                            offset2 = std::min(offset2, i + 1 - suffixMatchingPosition);
                        }
                        int t = i + 1;
                        while(t < patternSize)
                        {
                            if (prefix[patternSize - t])
                            {
                                offset2 = std::min(offset2, t);
                                break;
                            }
                            else
                                t++;
                        }
                    }
                    k += offset2;
                } else
                {
                    return k;
                }
            }
            return -1;
        }
    };
}