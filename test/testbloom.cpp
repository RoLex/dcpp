#include "testbase.h"

#include <dcpp/HashBloom.h>
#include <dcpp/HashValue.h>
#include <dcpp/TigerHash.h>

using namespace dcpp;

struct Hasher {
	static const size_t BITS = 1024;
	static const size_t BYTES = BITS / 8;
};

TEST(testbloom, test_0)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(8, 1024, 24);
	bloom.add(TTHValue("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_1)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(8, 1024, 24);
	bloom.add(TTHValue("BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_2)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(8, 1024, 24);
	bloom.add(TTHValue("QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAAAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_3)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(8, 1024, 24);
	bloom.add(TTHValue("BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.add(TTHValue("QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAQAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_4)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(8, 1024, 24);
	bloom.add(TTHValue("UDRJ6EGCH3CGWIIU2V6CH7VLFN4N2PCZKSPTBQA"));
	bloom.copy_to(v);
	ASSERT_EQ("AAAAAAAABAAAAAAAAAAAAAAAAAAAAAEAAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQACAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_5)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(2, 1024, 64);
	bloom.add(TTHValue("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_6)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(2, 1024, 64);
	bloom.add(TTHValue("BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_7)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(2, 1024, 64);
	bloom.add(TTHValue("QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAAAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_8)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(2, 1024, 64);
	bloom.add(TTHValue("BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.add(TTHValue("QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	bloom.copy_to(v);
	ASSERT_EQ("AEAQAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}

TEST(testbloom, test_9)
{
	HashBloom bloom;
	ByteVector v;
	bloom.reset(2, 1024, 64);
	bloom.add(TTHValue("UDRJ6EGCH3CGWIIU2V6CH7VLFN4N2PCZKSPTBQA"));
	bloom.copy_to(v);
	ASSERT_EQ("AAAAAAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
		HashValue<Hasher>(&v[0]).toBase32());
}
