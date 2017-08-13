/*
 * Copyright (c) 2011, Fabian Greif
 * Copyright (c) 2012, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/math/matrix.hpp>

#include "matrix_test.hpp"

void
MatrixTest::testConstruction()
{
	const int16_t m[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	modm::Matrix<int16_t, 3, 3> a(m);
	
	TEST_ASSERT_EQUALS(a[0][0], 1);
	TEST_ASSERT_EQUALS(a[0][1], 2);
	TEST_ASSERT_EQUALS(a[0][2], 3);
	TEST_ASSERT_EQUALS(a[1][0], 4);
	TEST_ASSERT_EQUALS(a[1][1], 5);
	TEST_ASSERT_EQUALS(a[1][2], 6);
	TEST_ASSERT_EQUALS(a[2][0], 7);
	TEST_ASSERT_EQUALS(a[2][1], 8);
	TEST_ASSERT_EQUALS(a[2][2], 9);
	
	const int16_t n[] = {
		1, 2,
		3, 4,
		5, 6,
	};
	
	modm::Matrix<int16_t, 3, 2> b(n);
	
	TEST_ASSERT_EQUALS(b.getNumberOfRows(), 3);
	TEST_ASSERT_EQUALS(b.getNumberOfColumns(), 2);
	
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 2);
	TEST_ASSERT_EQUALS(b[1][0], 3);
	TEST_ASSERT_EQUALS(b[1][1], 4);
	TEST_ASSERT_EQUALS(b[2][0], 5);
	TEST_ASSERT_EQUALS(b[2][1], 6);
}

void
MatrixTest::testAssign()
{
	modm::Matrix<int16_t, 3, 2> a;
	
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	a[2][0] = 5;
	a[2][1] = 6;
	
	TEST_ASSERT_EQUALS(a[0][0], 1);
	TEST_ASSERT_EQUALS(a[0][1], 2);
	TEST_ASSERT_EQUALS(a[1][0], 3);
	TEST_ASSERT_EQUALS(a[1][1], 4);
	TEST_ASSERT_EQUALS(a[2][0], 5);
	TEST_ASSERT_EQUALS(a[2][1], 6);
}

void
MatrixTest::testIdentityMatrix()
{
	modm::Matrix<int16_t, 3, 3> a = modm::Matrix<int16_t, 3, 3>::identityMatrix();
	
	for (uint_fast8_t i = 0; i < 3; ++i)
	{
		for (uint_fast8_t j = 0; j < 3; ++j)
		{
			if (i == j) {
				TEST_ASSERT_EQUALS(a[i][j], 1);
			}
			else {
				TEST_ASSERT_EQUALS(a[i][j], 0);
			}
		}
	}
}

void
MatrixTest::testZeroMatrix()
{
	modm::Matrix<int16_t, 3, 3> a = modm::Matrix<int16_t, 3, 3>::zeroMatrix();
	
	for (uint_fast8_t i = 0; i < 3; ++i)
	{
		for (uint_fast8_t j = 0; j < 3; ++j)
		{
			TEST_ASSERT_EQUALS(a[i][j], 0);
		}
	}
}

void
MatrixTest::testSubMatrix()
{
	const int16_t m[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	modm::Matrix<int16_t, 3, 3> a(m);
	
	modm::Matrix<int16_t, 2, 2> b = a.subMatrix<2, 2>(1, 1);
	
	TEST_ASSERT_EQUALS(b[0][0], 5);
	TEST_ASSERT_EQUALS(b[0][1], 6);
	TEST_ASSERT_EQUALS(b[1][0], 8);
	TEST_ASSERT_EQUALS(b[1][1], 9);
	
	modm::Matrix<int16_t, 2, 2> c = a.subMatrix<2, 2>(0, 0);
	
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 2);
	TEST_ASSERT_EQUALS(c[1][0], 4);
	TEST_ASSERT_EQUALS(c[1][1], 5);
	
	modm::Matrix<int16_t, 3, 2> d = a.subMatrix<3, 2>(0, 1);
	
	TEST_ASSERT_EQUALS(d[0][0], 2);
	TEST_ASSERT_EQUALS(d[0][1], 3);
	TEST_ASSERT_EQUALS(d[1][0], 5);
	TEST_ASSERT_EQUALS(d[1][1], 6);
	TEST_ASSERT_EQUALS(d[2][0], 8);
	TEST_ASSERT_EQUALS(d[2][1], 9);
}

void
MatrixTest::testAccess()
{
	const int16_t m[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	modm::Matrix<int16_t, 3, 3> a(m);
	
	modm::Matrix<int16_t, 3, 1> b = a.getColumn(1);
	
	TEST_ASSERT_EQUALS(b[0][0], 2);
	TEST_ASSERT_EQUALS(b[0][1], 5);
	TEST_ASSERT_EQUALS(b[0][2], 8);
	
	modm::Matrix<int16_t, 1, 3> c = a.getRow(2);
	
	TEST_ASSERT_EQUALS(c[0][0], 7);
	TEST_ASSERT_EQUALS(c[0][1], 8);
	TEST_ASSERT_EQUALS(c[0][2], 9);
}

void
MatrixTest::testCompare()
{
	const int16_t m[] = {
		1, 2,
		3, 4,
	};
	
	modm::Matrix<int16_t, 2, 2> a(m);
	modm::Matrix<int16_t, 2, 2> b(a);
	
	TEST_ASSERT_TRUE(a == b);
	TEST_ASSERT_FALSE(a != b);
	
	b[1][1] = 5;
	
	TEST_ASSERT_FALSE(a == b);
	TEST_ASSERT_TRUE(a != b);
	
	b[1][1] = 4;
	
	TEST_ASSERT_TRUE(a == b);
	TEST_ASSERT_FALSE(a != b);
}

void
MatrixTest::testArithmetics()
{
	const int16_t m[] = {
		1, 2,
		3, 4,
	};
	
	modm::Matrix<int16_t, 2, 2> a(m);
	modm::Matrix<int16_t, 2, 2> b(a);
	
	-a;
	TEST_ASSERT_EQUALS(a, b);
	a = -a;
	TEST_ASSERT_EQUALS(a[0][0], -1);
	TEST_ASSERT_EQUALS(a[0][1], -2);
	TEST_ASSERT_EQUALS(a[1][0], -3);
	TEST_ASSERT_EQUALS(a[1][1], -4);
	
	modm::Matrix<int16_t, 2, 2> c = b - a;
	TEST_ASSERT_EQUALS(c[0][0], 2);
	TEST_ASSERT_EQUALS(c[0][1], 4);
	TEST_ASSERT_EQUALS(c[1][0], 6);
	TEST_ASSERT_EQUALS(c[1][1], 8);
	
	c = c + a;
	TEST_ASSERT_EQUALS(c, b);
	
	a = c * 2;
	TEST_ASSERT_EQUALS(a[0][0], 2);
	TEST_ASSERT_EQUALS(a[0][1], 4);
	TEST_ASSERT_EQUALS(a[1][0], 6);
	TEST_ASSERT_EQUALS(a[1][1], 8);
	
	c = a / 2;
	TEST_ASSERT_EQUALS(c, b);
	
	c *= 2;
	TEST_ASSERT_EQUALS(c, a);
	
	c /= 2;
	TEST_ASSERT_EQUALS(c, b);
	
	c += b;
	TEST_ASSERT_EQUALS(c, a);
	
	c -= b;
	TEST_ASSERT_EQUALS(c, b);
}

void
MatrixTest::testMatrixMultiplicationInPlace()
{
	const int16_t m[] = {
		1, 2,
		3, 4,
	};
	
	const int16_t n[] = {
		1, 2,
		1, 2,
	};
	
	modm::Matrix<int16_t, 2, 2> a(m);
	modm::Matrix<int16_t, 2, 2> b(n);
	
	a *= b;
	TEST_ASSERT_EQUALS(a[0][0], 3);
	TEST_ASSERT_EQUALS(a[0][1], 6);
	TEST_ASSERT_EQUALS(a[1][0], 7);
	TEST_ASSERT_EQUALS(a[1][1], 14);
}

void
MatrixTest::testMatrixMultiplication()
{
	const int16_t m[] = {
		1,
		2,
		3,
	};
	
	modm::Matrix<int16_t, 3, 1> a(m);
	modm::Matrix<int16_t, 1, 3> b(m);
	
	modm::Matrix<int16_t, 3, 3> c = a * b;
	
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 2);
	TEST_ASSERT_EQUALS(c[0][2], 3);
	TEST_ASSERT_EQUALS(c[1][0], 2);
	TEST_ASSERT_EQUALS(c[1][1], 4);
	TEST_ASSERT_EQUALS(c[1][2], 6);
	TEST_ASSERT_EQUALS(c[2][0], 3);
	TEST_ASSERT_EQUALS(c[2][1], 6);
	TEST_ASSERT_EQUALS(c[2][2], 9);
	
	modm::Matrix<int16_t, 1, 1> d = b * a;
	
	TEST_ASSERT_EQUALS(d[0][0], 14);
	
	const int16_t n[] = {
		1, 2,
		3, 4,
		5, 6,
	};
	
	modm::Matrix<int16_t, 3, 2> e(n);
	modm::Matrix<int16_t, 2, 3> f(n);
	
	c = e * f;
	
	TEST_ASSERT_EQUALS(c[0][0], 9);
	TEST_ASSERT_EQUALS(c[0][1], 12);
	TEST_ASSERT_EQUALS(c[0][2], 15);
	TEST_ASSERT_EQUALS(c[1][0], 19);
	TEST_ASSERT_EQUALS(c[1][1], 26);
	TEST_ASSERT_EQUALS(c[1][2], 33);
	TEST_ASSERT_EQUALS(c[2][0], 29);
	TEST_ASSERT_EQUALS(c[2][1], 40);
	TEST_ASSERT_EQUALS(c[2][2], 51);
	
	modm::Matrix<int16_t, 2, 2> g = f * e;
	
	TEST_ASSERT_EQUALS(g[0][0], 22);
	TEST_ASSERT_EQUALS(g[0][1], 28);
	TEST_ASSERT_EQUALS(g[1][0], 49);
	TEST_ASSERT_EQUALS(g[1][1], 64);
}

void
MatrixTest::testTranspose()
{
	const int16_t m[] = {
		1, 2,
		3, 4,
		5, 6,
	};
	
	modm::Matrix<int16_t, 3, 2> a(m);
	modm::Matrix<int16_t, 2, 3> b(a.asTransposed());
	
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 3);
	TEST_ASSERT_EQUALS(b[0][2], 5);
	TEST_ASSERT_EQUALS(b[1][0], 2);
	TEST_ASSERT_EQUALS(b[1][1], 4);
	TEST_ASSERT_EQUALS(b[1][2], 6);
	
	const int16_t n[] = {
		1, 2,
		3, 4,
	};
	
	modm::Matrix<int16_t, 2, 2> c(n);
	
	c.transpose();
	
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 3);
	TEST_ASSERT_EQUALS(b[1][0], 2);
	TEST_ASSERT_EQUALS(b[1][1], 4);
}

void
MatrixTest::testReplace()
{
	const int16_t m[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	modm::Matrix<int16_t, 3, 3> a(m);
	modm::Matrix<int16_t, 3, 3> b;
	
	b.replace(m);
	TEST_ASSERT_EQUALS(a, b);
	
	b = modm::Matrix<int16_t, 3, 3>::zeroMatrix();
	b.replace(0, 0, a);
	TEST_ASSERT_EQUALS(a, b);
	
	modm::Matrix<int16_t, 2, 2> c = a.subMatrix<2, 2>(1, 0);
	
	a.replace(0, 1, c);
	TEST_ASSERT_EQUALS(a[0][0], 1);
	TEST_ASSERT_EQUALS(a[0][1], 4);
	TEST_ASSERT_EQUALS(a[0][2], 5);
	TEST_ASSERT_EQUALS(a[1][0], 4);
	TEST_ASSERT_EQUALS(a[1][1], 7);
	TEST_ASSERT_EQUALS(a[1][2], 8);
	TEST_ASSERT_EQUALS(a[2][0], 7);
	TEST_ASSERT_EQUALS(a[2][1], 8);
	TEST_ASSERT_EQUALS(a[2][2], 9);
	
	const int16_t n[] = { 1, 2 };
	modm::Matrix<int16_t, 2, 1> column(n);
	
	c.replaceColumn(1, column);
	
	TEST_ASSERT_EQUALS(c[0][0], 4);
	TEST_ASSERT_EQUALS(c[0][1], 1);
	TEST_ASSERT_EQUALS(c[1][0], 7);
	TEST_ASSERT_EQUALS(c[1][1], 2);
	
	const int16_t o[2] = { 10, 12 };
	modm::Matrix<int16_t, 1, 2> row(o);
	
	c.replaceRow(0, row);
	
	TEST_ASSERT_EQUALS(c[0][0], 10);
	TEST_ASSERT_EQUALS(c[0][1], 12);
	TEST_ASSERT_EQUALS(c[1][0], 7);
	TEST_ASSERT_EQUALS(c[1][1], 2);
}

void
MatrixTest::testAddRowColumn()
{
	const int16_t in[] = {
		1, 2,
		3, 4,
	};
	const int16_t in2[] = {
		5, 6,
	};
	
	modm::Matrix<int16_t, 2, 2> a(in);
	
	modm::Matrix<int16_t, 1, 2> row2(in2);
	modm::Matrix<int16_t, 3, 2> b = a.addRow(0, row2);
	TEST_ASSERT_EQUALS(b[0][0], 5);
	TEST_ASSERT_EQUALS(b[0][1], 6);
	TEST_ASSERT_EQUALS(b[1][0], 1);
	TEST_ASSERT_EQUALS(b[1][1], 2);
	TEST_ASSERT_EQUALS(b[2][0], 3);
	TEST_ASSERT_EQUALS(b[2][1], 4);
	
	b = a.addRow(1, row2);
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 2);
	TEST_ASSERT_EQUALS(b[1][0], 5);
	TEST_ASSERT_EQUALS(b[1][1], 6);
	TEST_ASSERT_EQUALS(b[2][0], 3);
	TEST_ASSERT_EQUALS(b[2][1], 4);
	
	b = a.addRow(2, row2);
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 2);
	TEST_ASSERT_EQUALS(b[1][0], 3);
	TEST_ASSERT_EQUALS(b[1][1], 4);
	TEST_ASSERT_EQUALS(b[2][0], 5);
	TEST_ASSERT_EQUALS(b[2][1], 6);
	
	const int16_t in3[] = {
		7, 8, 9,
	};
	
	modm::Matrix<int16_t, 3, 1> colum3(in3);
	modm::Matrix<int16_t, 3, 3> c = b.addColumn(0, colum3);
	TEST_ASSERT_EQUALS(c[0][0], 7);
	TEST_ASSERT_EQUALS(c[0][1], 1);
	TEST_ASSERT_EQUALS(c[0][2], 2);
	TEST_ASSERT_EQUALS(c[1][0], 8);
	TEST_ASSERT_EQUALS(c[1][1], 3);
	TEST_ASSERT_EQUALS(c[1][2], 4);
	TEST_ASSERT_EQUALS(c[2][0], 9);
	TEST_ASSERT_EQUALS(c[2][1], 5);
	TEST_ASSERT_EQUALS(c[2][2], 6);
	
	c = b.addColumn(1, colum3);
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 7);
	TEST_ASSERT_EQUALS(c[0][2], 2);
	TEST_ASSERT_EQUALS(c[1][0], 3);
	TEST_ASSERT_EQUALS(c[1][1], 8);
	TEST_ASSERT_EQUALS(c[1][2], 4);
	TEST_ASSERT_EQUALS(c[2][0], 5);
	TEST_ASSERT_EQUALS(c[2][1], 9);
	TEST_ASSERT_EQUALS(c[2][2], 6);
	
	c = b.addColumn(2, colum3);
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 2);
	TEST_ASSERT_EQUALS(c[0][2], 7);
	TEST_ASSERT_EQUALS(c[1][0], 3);
	TEST_ASSERT_EQUALS(c[1][1], 4);
	TEST_ASSERT_EQUALS(c[1][2], 8);
	TEST_ASSERT_EQUALS(c[2][0], 5);
	TEST_ASSERT_EQUALS(c[2][1], 6);
	TEST_ASSERT_EQUALS(c[2][2], 9);
}

void
MatrixTest::testRemoveRowColumn()
{
	const int16_t m[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	modm::Matrix<int16_t, 3, 3> a(m);
	modm::Matrix<int16_t, 3, 2> b = a.removeColumn(0);
	TEST_ASSERT_EQUALS(b[0][0], 2);
	TEST_ASSERT_EQUALS(b[0][1], 3);
	TEST_ASSERT_EQUALS(b[1][0], 5);
	TEST_ASSERT_EQUALS(b[1][1], 6);
	TEST_ASSERT_EQUALS(b[2][0], 8);
	TEST_ASSERT_EQUALS(b[2][1], 9);
	
	b = a.removeColumn(1);
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 3);
	TEST_ASSERT_EQUALS(b[1][0], 4);
	TEST_ASSERT_EQUALS(b[1][1], 6);
	TEST_ASSERT_EQUALS(b[2][0], 7);
	TEST_ASSERT_EQUALS(b[2][1], 9);
	
	b = a.removeColumn(2);
	TEST_ASSERT_EQUALS(b[0][0], 1);
	TEST_ASSERT_EQUALS(b[0][1], 2);
	TEST_ASSERT_EQUALS(b[1][0], 4);
	TEST_ASSERT_EQUALS(b[1][1], 5);
	TEST_ASSERT_EQUALS(b[2][0], 7);
	TEST_ASSERT_EQUALS(b[2][1], 8);
	
	modm::Matrix<int16_t, 2, 3> c = a.removeRow(0);
	TEST_ASSERT_EQUALS(c[0][0], 4);
	TEST_ASSERT_EQUALS(c[0][1], 5);
	TEST_ASSERT_EQUALS(c[0][2], 6);
	TEST_ASSERT_EQUALS(c[1][0], 7);
	TEST_ASSERT_EQUALS(c[1][1], 8);
	TEST_ASSERT_EQUALS(c[1][2], 9);
	
	c = a.removeRow(1);
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 2);
	TEST_ASSERT_EQUALS(c[0][2], 3);
	TEST_ASSERT_EQUALS(c[1][0], 7);
	TEST_ASSERT_EQUALS(c[1][1], 8);
	TEST_ASSERT_EQUALS(c[1][2], 9);
	
	c = a.removeRow(2);
	TEST_ASSERT_EQUALS(c[0][0], 1);
	TEST_ASSERT_EQUALS(c[0][1], 2);
	TEST_ASSERT_EQUALS(c[0][2], 3);
	TEST_ASSERT_EQUALS(c[1][0], 4);
	TEST_ASSERT_EQUALS(c[1][1], 5);
	TEST_ASSERT_EQUALS(c[1][2], 6);
}

void
MatrixTest::testDeterminant()
{
	const int16_t m[9] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	
	// determinate 3x3
	modm::Matrix<int16_t, 3, 3> a(m);
	TEST_ASSERT_EQUALS(a.determinant(), 0);
	
	a[2][2] = 10;
	TEST_ASSERT_EQUALS(a.determinant(), -3);
	
	// determinate 2x2
	modm::Matrix<int16_t, 2, 2> b = a.subMatrix<2, 2>(0, 0);
	TEST_ASSERT_EQUALS(b.determinant(), -3);
	
	modm::Matrix<int16_t, 2, 2> c = a.subMatrix<2, 2>(1, 1);
	TEST_ASSERT_EQUALS(c.determinant(), 2);
	
	// determinate 1x1
	modm::Matrix<int16_t, 1, 1> d = a.subMatrix<1, 1>(1, 1);
	TEST_ASSERT_EQUALS(d.determinant(), 5);
}