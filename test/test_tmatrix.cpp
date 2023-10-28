#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> cpy = TDynamicMatrix<int>(m);
	
	ASSERT_EQ(true, cpy == m); // два выражения равны между собой
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> cpy = TDynamicMatrix<int>(m);
	m[0][0] = 12;
	ASSERT_NE(m[0][0], cpy[0][0]); // два выражения не равны между собой
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);
	ASSERT_NO_THROW(m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 12;
	int t = m[0][0];
	ASSERT_EQ(t, 12);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-1][0] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(4);
	ASSERT_ANY_THROW(m[100000000000000000][0] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(4);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(4), m1(4);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int>m(4), m1(5);
	m = m1;
	ASSERT_EQ(m.size(), m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int>m(4), m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(4), m1(4);
	bool t = true;
	ASSERT_EQ(t, m == m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(4);
	 bool t = (m == m);
	ASSERT_EQ(true, t);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(4), m1(5);
	bool t = (m != m1);
	ASSERT_EQ(true, t);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3), m1(3);
	m[0][1] = 1;
	m1[0][1] = 2;
	m = m + m1;
	ASSERT_EQ(3, m[0][1]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m1(4);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), m(2);
	m1[0][0] = 1;
	m1[1][1] = 1;
	m2[1][0] = 1;
	m2[0][1] = 1;
	ASSERT_NO_THROW(m1 / m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(4);
	ASSERT_ANY_THROW(m1 / m2);
}

