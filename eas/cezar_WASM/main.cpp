#include <string>
#include <emscripten.h>

using namespace std;

static string secret;

extern "C" {

EMSCRIPTEN_KEEPALIVE
void encrypt(const char* text, const char* key)
{
    secret = "";

    string input = text;
    string password = key;

    if (password.length() != 32)
    {
        secret = "KLUCZ MUSI MIEC 32 ZNAKI";
        return;
    }

    for (int i = 0; i < input.length(); i++)
    {
        unsigned char znak = input[i];
        unsigned char keyChar = password[i % 32];

        secret += static_cast<char>(znak ^ keyChar);
    }
}

EMSCRIPTEN_KEEPALIVE
const char* getResult()
{
    return secret.data();
}

EMSCRIPTEN_KEEPALIVE
int getResultLength()
{
    return secret.size();
}

}