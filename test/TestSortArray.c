#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"
#include "array.h"

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

TEST(SortArray, TestSortArray1) // Testa se o vetor de entrada sai como esperado
{
    // Random order
    for(int i = 0; i < 7; i++) {
        sort_array(values, n, i);
        TEST_ASSERT_EQUAL_INT_ARRAY (expected, values, n);
    }
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
    for(int i = 0; i < 7; i++) {
        sort_array(values, n, i);
        int size = sizeof(values) / sizeof(int);
        TEST_ASSERT_EQUAL_INT (size, n);
    }
}

// Testa se o número de elementos a serem ordenados é maior que zero
TEST(SortArray, TestSortArray4)
{
    for(int i = 0; i < 7; i++) {
        sort_array(values, n, i);
        TEST_ASSERT_GREATER_THAN (0, n);
    }
}

// Testa se o tamanho do array a ser ordenado é maior que zero
TEST(SortArray, TestSortArray5)
{
  int size = sizeof(values) / sizeof(int);
  TEST_ASSERT_GREATER_THAN (0, size);
}

// Testa se o tamanho do array a ser ordenado se mantém maior que zero
TEST(SortArray, TestSortArray6)
{
    for(int i = 0; i < 7; i++) {
        sort_array(values, n, i);
        int size = sizeof(values) / sizeof(int);
        TEST_ASSERT_GREATER_THAN (0, size);
    }
}

TEST(SortArray, TestSortArray7)
{
    n = 10;

    for( int state = 0; state <= 3; state++){ // state: RANDOM_ORDER, ASCENDING_ORDER, DESCENDING_ORDER, ALMOST_ORDERED
        // Create the vector with the specified size and situation
        int *vet = generate_array(n, state);
        printf("\n\nOrig.:  ");
        for(int i=0; i<n; i++){
            printf("%d ", vet[i]);
        }
        for(int algorithm = 0; algorithm < 7; algorithm++) { // algorithm: SELECTION, INSERTION, SHELL, QUICK, HEAP, MERGE
            sort_array(vet, n, algorithm);
            printf("\nSorted: ");
            for(int i=0; i<n; i++) {
                printf("%d ", vet[i]);
            }
        }
    }
}

TEST(SortArray, TestSortArray8)
{
    n = 5;

    int vet[] = {0, 0, 0, 0, 0};
    printf("\n\nOrig.: ");
    for(int i=0; i<n; i++){
        printf(" %2d", vet[i]);
    }
    for(int algorithm = 0; algorithm < 7; algorithm++) { // algorithm: SELECTION, INSERTION, SHELL, QUICK, HEAP, MERGE
        sort_array(vet, n, algorithm);
        printf("\nSorted:");
        for(int i=0; i<n; i++) {
            printf(" %2d", vet[i]);
        }
    }
}

TEST(SortArray, TestSortArray9)
{
    n = 5;

    int vet[] = {-1, -5, -2, -4, -3};
    printf("\n\nOrig.: ");
    for(int i=0; i<n; i++){
        printf(" %2d", vet[i]);
    }
    for(int algorithm = 0; algorithm < 7; algorithm++) { // algorithm: SELECTION, INSERTION, SHELL, QUICK, HEAP, MERGE
        sort_array(vet, n, algorithm);
        printf("\nSorted:");
        for(int i=0; i<n; i++) {
            printf(" %2d", vet[i]);
        }
    }
}