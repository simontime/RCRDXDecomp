#include "Hash.h"

namespace Hash
{
	uint32_t EncodeU16(uint16_t u16)
	{
		return hashTable[u16 >> 8] ^ hashTable[u16 & 0xFF];
	}

	uint32_t FromBuffer(const unsigned char *buffer, int len)
	{
		uint32_t hash = 0;

		if (len)
		{
			while (len--)
				hash = hashTable[*buffer++ ^ (hash & 0xFF)] ^ hash >> 1;
		}

		return hash;
	}

	uint32_t FromBufferBool(const unsigned char *buffer, int len)
	{
		uint32_t hash = 0;

		if (len)
		{
			while (len--)
				hash = hashTable[(*buffer++ != 0) ^ (hash & 0xFF)] ^ hash >> 1;
		}

		return hash;
	}

	uint32_t FromStr(const char *str)
	{
		uint32_t hash = 0;

		if (str != nullptr && *str)
		{
			while (*str)
			{
				char ch = *str++;

				if (ch - 'a' < 0x1A)
					ch &= 0xDF;

				hash = hashTable[(ch ^ hash) & 0xFF] ^ hash << 1;
			}
		}

		return hash;
	}

	uint32_t FromStr(const char *str, int len)
	{
		uint32_t hash = 0;

		if (len)
		{
			while (len--)
			{
				char ch = *str++;

				if (ch - 'a' < 0x1A)
					ch &= 0xDF;

				hash = hashTable[(ch ^ hash) & 0xFF] ^ hash << 1;
			}
		}

		return hash;
	}

	uint32_t Lookup(uint8_t val)
	{
		return hashTable[val];
	}

	void XorBuffer(uint8_t *buffer, int len, uint32_t val)
	{
		if (len > 0)
		{
			while (len--)
				*buffer++ ^= xorTable[val++ & 0x3FF];
		}
	}
}
