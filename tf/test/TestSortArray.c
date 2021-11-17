#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SortArray);

TEST_SETUP(SortArray)
{
}

TEST_TEAR_DOWN(SortArray)
{
}

int values[] = { 40, 10, 100, 90, 20, 25 };
int expected[] = { 10, 20, 25, 40, 90, 100 };
int n = 6;
int method = SELECTION;

TEST(SortArray, TestSortArray1) // Testa se o vetor de entrada sai como esperado
{
  sort_array(values, n, SELECTION);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
  sort_array(values, n, INSERTION);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
  sort_array(values, n, SHELL);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
  sort_array(values, n, QUICK);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
  sort_array(values, n, MERGE);
  TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
}

// Testa se o tamanho do vetor é igual ao número de elementos a serem ordenados
TEST(SortArray, TestSortArray2)
{
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_EQUAL_INT (size, n);
}

// Testa se o tamanho do vetor se mantém igual ao número de elementos a serem ordenados
TEST(SortArray, TestSortArray3)
{
  sort_array(values, n, method);
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_EQUAL_INT (size, n);
}

// Testa se o número de elementos a serem ordenados é maior que zero
TEST(SortArray, TestSortArray4)
{
  sort_array(values, n, method);
  TEST_ASSERT_GREATER_THAN (0, n);
}

// Testa se o tamanho do array a ser ordenado é maior que zero
TEST(SortArray, TestSortArray5)
{
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_GREATER_THAN (0, size);
}

// Testa se o tamanho do array a ser ordenado se mantém que zero
TEST(SortArray, TestSortArray6)
{
  sort_array(values, n, method);
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_GREATER_THAN (0, size);
}