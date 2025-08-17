#include "suyudorunnerhelpers.h"
#include "veritywizard.h"

namespace tmc {
namespace suyudo {

std::vector<u8> buildMspcache(bool r13Pass, bool r18Pass, VerityWizard* vw, const std::string& password)
{
    std::mt19937_64* g = vw->getRngWithGlobalSeed();
    std::vector<u8> result = {
        0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x69, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x69, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x68,
        0x00, 0x00, 0x00, 0x74}; // Initialize with header
    std::vector<u8> r13Keyblob;
    std::vector<u8> r18Keyblob;
    if (r13Pass)
    {
        r13Keyblob = asciiToHex(base64Dec("REE2MTY5QzhBRTE1N0E2QzNEQjQwNUI3MEFDNENEQzE2NURCQTFFNEVGRkJCNTVEN0EwN0NCOTA5ODM1MEU5MDYwMjMwN0YyNEE4RDU0RDczMkI3RThDOTAzRENDNDQ5MDc1Rjg2RjMwNDc3OTAwQTlGMjc1NjIxM0Y3NEQzQ0U2NkQ4NjQyOTAzNjA1RjI5NzY0QzVCOUQxM0E1RkREMEY5NTg2ODZBOEUyMDUzODJCRTkwRjIyNUZFMzhBNEI4RjE1RDIwM0U1OUYyNTc5MEE0NTgyMkY3NjRGNDY4REZGQTYzNDhGNTlCMzVERDA3MTRERTZDQjVEQ0FDNjMxNDVENDIwMDYxN0NCMEY2OEEzQjIzQUFDQzUwREJDMTc4RjU4MDMyMDIwOUI4NDkxN0VGMEREOUMyMkI1QzMzRkQ3MUY3Q0IzNjY3OENDMEEzNTg1QTkwNEIyMDY3QTFFNUZCREUyRTVEMDM0M0I2NzI1OUM4NUMwMEQ2MEIzODc5NjdDQzdFOUJCQ0YzMTI2MjVCRTVFMDY5RjhBMENENjQ4NTdFQjA0REU0NkFDRjBBNDg3NzEyMTg5RUYzMjI5RjkwNTU5MjY4QjExMkI0QUMxQTU0N0Y1RjJGOTQ0MjMwMzM4N0ZCMEE2MzBEN0IxRTgyRjkwOTgzQTI1NjJCOTA="));
    }
    else
    {
        for (u64 i = 0; i < 256; i++)
        {
            r13Keyblob.push_back((*g)() & 0xFF);
        }
    }
    if (r18Pass)
    {
        r18Keyblob = asciiToHex(base64Dec("NkNDRDg3NkQyRTJGRUNCNUE2Q0E1RkYxN0ZCQjM2NzNBMDlENjM1MEYwMzhFQzhDOUEyQTEyMTQ2OTdGQ0IwQzFFOTAxRjI5NDcxODg3MjgzNUUxNDk1QjQyQzdDQTUzNjVFOTUyM0YxNzk4MUM5QzFDNTMzOTRFRkJEMjVFOENENTA3MDJCRjdBNDY5QzA1NTlDOUNCRkYxRjMwRUMwMEVBRjhDNTlFOUEyQzMxRkZCMzFDRTE3OUI5QzRFRkJEODNCMkYxNjQzNzYzRTMwNTRCQzQ5NzcwNEIwNDdGMDg2MkZCRTk0NTI4RkIwMDhDQzFDNjU1RDU4RjBEMjBBNjk0Njg4NkY4QjAwQUVCREQ2RjlDMDJGOTdENEQ4QUZBQzAzREU5MDYzNzZGNDQxMTVGRkRBQkI4MEM0RTM3MUExOEUwQjJFOUEyOUQ1MEVBOTQ4OUY4RUU4REM3Nzk1RjJEMzhCN0IyNjk1QkMxM0E0ODgzQTRBMkJFMzYyMjczMjlGNDlBMjA3MzcwMjhGNkFFMTA5OTIxNDQzNjQzOTIwMTJCQjdBQkUzQThDNDhFMkQxNkI4MTYwMDIzRDdGQzFGQzgyREI4MUE0OThDMDY0MDU2OTVENzE4N0I5REY1RkFFODI4NzY3MTEzRTkzQUQ0OUE3MkMwRkU5MTdFNzQ="));
    }
    else
    {
        for (u64 i = 0; i < 256; i++)
        {
            r18Keyblob.push_back((*g)() & 0xFF);
        }
    }
    for (u64 i = 0; i < r13Keyblob.size(); i++)
    {
        result.push_back(r13Keyblob[i]);
    }
    for (u64 i = 0; i < r18Keyblob.size(); i++)
    {
        result.push_back(r18Keyblob[i]);
    }
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    std::u32string pwU32 = conv.from_bytes(password);
    std::vector<std::vector<u8>> keys(0);
    for (u64 i = 0; i < pwU32.size(); i++)
    {
        if (!(i & 3))
        {
            keys.push_back(std::vector<u8>(0));
        }
        for (u8 j = 3; j < 4; j--)
        {
            keys.back().push_back((u32(pwU32[i]) >> (j * 8)) & 0xFF);
        }
    }
    while (keys.back().size() != 16)
    {
        keys.back().push_back(255);
    }
    for (u64 i = keys.size() - 1; i < keys.size(); i--)
    {
        struct AES_ctx ctx;
        std::vector<u8> iv(16, 0);
        AES_init_ctx_iv(&ctx, keys[i].data(), iv.data());
        AES_CTR_xcrypt_buffer(&ctx, result.data(), result.size());
    }
    return result;
}

}
}
