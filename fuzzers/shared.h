#pragma once
#include "src/piex_types.h"

class FuzzingStreamInterface : public piex::StreamInterface {
    private:
        const std::vector<uint8_t> data;
    public:
        FuzzingStreamInterface(std::vector<uint8_t> data) :
            data(data)
        { }

        piex::Error GetData(
                const size_t offset,
                const size_t length,
                std::uint8_t* out) override {
            const size_t endpos = offset + length;

            if ( endpos < offset || endpos < length ) {
                /* Overflow */
                return piex::Error::kFail;

                /* Alternatively, abort() if piex is not expected to make
                 * size_t-overflowing requests */
            }

            if ( endpos > data.size() ) {
                return piex::Error::kFail;
            }

            /* memcpy with length = 0 is undefined */
            if ( length ) {
                std::memcpy(out, data.data() + offset, length);
            }

            return piex::Error::kOk;
        }
};
