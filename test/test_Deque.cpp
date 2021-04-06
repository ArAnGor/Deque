#include "Deque.h"
#include <gtest.h>

TEST(Deque, can_create_deque)
{
  ASSERT_NO_THROW(Deque<int> d);
}

TEST(Deque, new_deque_is_empty)
{
  Deque<int> d;
  EXPECT_EQ(true, d.IsEmpty());
}

TEST(Deque, can_add_front_elem)
{
  Deque<int> d;
  int i = 5;
  ASSERT_NO_THROW(d.PushFront(i));
  EXPECT_EQ(false, d.IsEmpty());
}

TEST(Deque, can_add_back_elem)
{
  Deque<int> d;
  int i = 42;
  ASSERT_NO_THROW(d.PushBack(i));
  EXPECT_EQ(false, d.IsEmpty());
}

TEST(Deque, can_del_front_elem)
{
  Deque<int> d;
  int i = 54;
  d.PushBack(i);
  ASSERT_NO_THROW(d.PopFront());
  EXPECT_EQ(true, d.IsEmpty());
}

TEST(Deque, can_del_back_elem)
{
  Deque<int> d;
  int i = 666;
  d.PushFront(i);
  ASSERT_NO_THROW(d.PopBack());
  EXPECT_EQ(true, d.IsEmpty());
}

TEST(Deque, can_get_front_elem)
{
  Deque<int> d;
  int i = 3;
  d.PushFront(i);
  ASSERT_NO_THROW(d.GetFront());
  EXPECT_EQ(3, d.GetFront());
}

TEST(Deque, can_get_back_elem)
{
  Deque<int> d;
  int i = 10;
  d.PushBack(i);
  ASSERT_NO_THROW(d.GetBack());
  EXPECT_EQ(10, d.GetBack());
}

TEST(Deque, throws_when_pop_empty_deque)
{
  Deque<int> d;
  ASSERT_ANY_THROW(d.PopFront());
  ASSERT_ANY_THROW(d.PopBack());
}

TEST(Deque, throws_when_get_empty_deque)
{
  Deque<int> d;
  ASSERT_ANY_THROW(d.GetFront());
  ASSERT_ANY_THROW(d.GetBack());
}
