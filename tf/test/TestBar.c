#include "bar.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Bar);

TEST_SETUP(Bar)
{
}

TEST_TEAR_DOWN(Bar)
{
}

int values[] = { 40, 10, 100, 90, 20, 25 };
int expected[] = { 10, 20, 25, 40, 90, 100 };
int n = 6;

TEST(Bar, TestBar1) // Testa se o vetor de entrada sai como esperado
{
  sort(values, n);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
}

// Testa se o tamanho do vetor é igual ao número de elementos a serem ordenados
TEST(Bar, TestBar2)
{
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_EQUAL_INT (size, n);
}

// Testa se o tamanho do vetor se mantém igual ao número de elementos a serem ordenados
TEST(Bar, TestBar3)
{
  sort(values, n);
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_EQUAL_INT (size, n);
}

// Testa se o número de elementos a serem ordenados é maior que zero
TEST(Bar, TestBar4)
{
  sort(values, n);
  TEST_ASSERT_GREATER_THAN (0, n);
}

// Testa se o tamanho do array a ser ordenado é maior que zero
TEST(Bar, TestBar5)
{
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_GREATER_THAN (0, size);
}

// Testa se o tamanho do array a ser ordenado se mantém que zero
TEST(Bar, TestBar6)
{
  sort(values, n);
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_GREATER_THAN (0, size);
}