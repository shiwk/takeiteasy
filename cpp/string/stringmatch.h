//
// Created by swk on 2019-08-23.
//

#ifndef CPP_STRINGMATCH_H
#define CPP_STRINGMATCH_H


namespace happycoding{
    class StringMatch {
    public:
        virtual int indexOf(const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize) = 0;
    };
}

#endif //CPP_STRINGMATCH_H
