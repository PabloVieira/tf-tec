#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Bar)
{
  RUN_TEST_CASE(Bar, TestBar1);
  RUN_TEST_CASE(Bar, TestBar2);
  RUN_TEST_CASE(Bar, TestBar3);
  RUN_TEST_CASE(Bar, TestBar4);
  RUN_TEST_CASE(Bar, TestBar5);
  RUN_TEST_CASE(Bar, TestBar6);
}
