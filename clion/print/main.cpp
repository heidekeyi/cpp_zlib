#include "print.h"

int main() {
    ZLIB::print p;
    p
            .inc(3)
            .row_col(3, 3)
            .dec(3)
            .pyramid(6)
            .mul()
            .daf()
            .fab(0).fab(1).fab(2).fab(3).fab(5)
            .bin(19).bin(255).bin(256)
            .dec("1001011").bin(75)
            .dec("0").dec("01").dec("10").dec("11")
            .reverse("hello world")
            .chicken()
            .word("last week   i went to company by   bike")
            .str(std::string{"last week   i went to company by   bike"}).str(" hello  world  Good  ");
    return 0;
}
