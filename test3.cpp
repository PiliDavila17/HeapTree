#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "PriorityQueue.h"

TEST_CASE("testing top", "[List]")
{
  PriorityQueue<int> pq;
  pq.push(10);
  pq.push(50);
  pq.push(30);
  pq.push(20);
  pq.push(60);
  pq.push(70);
  pq.push(80);
  REQUIRE(pq.top() == 80);
  REQUIRE(pq.getSize() == 7);
}