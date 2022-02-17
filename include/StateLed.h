#pragma once

enum state{ kIdle = 0, kListening = 1, kAnalysing = 2, kReplying = 3 };

class StateLed {
    private:
        bool turned_on_;
        state state_;

    public:
        int getstate();
        void resetstate();
        void setstate(state);
};
