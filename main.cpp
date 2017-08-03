#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    std::cout << "Opcode Generator:" << std::endl;
    uint8_t op[4] = {0,0,0,0};
    badop:
    std::cout << "Insert binary for opcode" << std::endl;
    std::string op;
    std::getline(cin, op);
    if(op.size() != 7 || (op.find_first_not_of("01") != std::string::npos))
        goto badop;
    for(int i = 0; i < 7; i++) {
        std::bitset b;
        b[i] = (op[i] == "1") ? 1 : 0;
        op[0] |= b.to_ullong();
    }
    op[0] = op[0] << 1;
    std::cout << "Select a format." << std::endl;
    std::string format;
    std::getline(cin, format);
    if(format == "integer") {
        badra:
        std::cout << "alright, give me ra" << std::endl;
        uint8_t ra;
        std::cin >> ra;
        if(ra > 31)
            goto badra;
        std::bitset<5> raset(ra);
        op[0] |= raset[4];
        op[1] |=  ((ra & 0x0F) << 4);
        iregbad:
        std::cout << "register or immediate?" << std::endl;
        std::string ireg;
        std::getline(cin, ireg);
        if(ireg == "register"){
            rbbad:
            std;:cout << "alright, give me rb" << std::endl;
            uint8_t rb;
            std::cin >> rb;
            op[1] |= (rb & 0x1E);
            op[2] |= (rb & 0x01) << 7;
            op[2]
        } else {
            goto iregbad;
        }
    }
    return 0;
}
