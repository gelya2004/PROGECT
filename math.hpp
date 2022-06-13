#pragma once
using namespace std;
class Matrix
{
public:

    Matrix(int n, int m)
    {
        m_n = n;
        m_m = m;
        m_mat = new double* [m_n];
        for (int i = 0; i < m_n; i++)
        {
            m_mat[i] = new double[m_m];
        }
    }


    Matrix(const Matrix& mat)
    {
        m_n = mat.m_n;
        m_m = mat.m_m;
        m_mat = new double* [m_n];
        for (int i = 0; i < m_n; i++)
        {
            m_mat[i] = new double[m_m];
        }
        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                m_mat[i][j] = mat.m_mat[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& mat)
    {
        m_n = mat.m_n;
        m_m = mat.m_m;

        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                m_mat[i][j] = mat.m_mat[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& mat)
    {
        Matrix tmp(m_n, mat.m_m);
        if (m_m != mat.m_m && m_n != mat.m_n)
        {
            cout << "matrices have a different type " << endl;
            return mat;
        }
        if (m_m != mat.m_m && m_n != mat.m_n)
        {
            cout << "matrices have a different type " << endl;
            return mat;
        }
        else
        {
            for (int i = 0; i < m_n; i++)
            {
                for (int j = 0; j < m_m; j++)
                {
                    tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
                }
            }

        }
        return tmp;
    }

    Matrix operator-(const Matrix& mat)
    {
        Matrix tmp(m_n, mat.m_m);
        if (m_m != mat.m_m && m_n != mat.m_n)
        {
            cout << "matrices have a different type " << endl;
            return mat;
        }
        else
        {
            for (int i = 0; i < m_n; i++)
            {
                for (int j = 0; j < m_m; j++)
                {
                    tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
                }
            }
        }
        return tmp;
    }

    Matrix operator*(const Matrix& mat)
    {
        Matrix tmp(m_n, mat.m_m);
        if (m_m != mat.m_n)
        {
            cout << "matrices have a different type " << endl;
        }
        else
        {
            for (int i = 0; i < m_n; i++)
            {
                for (int j = 0; j < mat.m_m; j++)
                {
                    tmp.m_mat[i][j] = 0;
                    for (int k = 0; k < mat.m_n; k++)
                    {
                        tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
                    }
                }
            }
        }
        return tmp;
    }

    ~Matrix()
    {
        for (int i = 0; i < m_n; i++)
        {
            delete[] m_mat[i];
        }
        delete m_mat;
    }

    double DET()
    {
        if ((m_n != m_m) && (m_n != 2) && (m_n != 3))
        {
            cout << "the operation is not valid " << endl;
        }

        else if (m_n == 2)
        {
            double det = 0;
            det = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
            return det;
        }

        else if (m_n == 3)
        {
            double det = 0;
            det = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
                + m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - m_mat[2][0] * m_mat[1][1] * m_mat[0][2] -
                m_mat[2][1] * m_mat[1][2] * m_mat[0][0] - m_mat[1][0] * m_mat[0][1] * m_mat[2][2];
            return det;
        }
    }

    Matrix reverse()
    {
        double Det = DET();
        Matrix tmp(m_n, m_m);
        if ((m_n == m_m && m_n == 2) || (m_n == m_m && m_n == 3))
        {
            if (Det == 0)
            {
                cout << "det = 0 " << endl;
            }
            else
            {
                if (m_n == 2)
                {
                    tmp.m_mat[0][0] = m_mat[1][1] / Det;
                    tmp.m_mat[0][1] = -m_mat[0][1] / Det;
                    tmp.m_mat[1][0] = -m_mat[1][0] / Det;
                    tmp.m_mat[1][1] = m_mat[0][0] / Det;
                    return tmp;
                }
                else if (m_n == 3)
                {
                    tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / Det;
                    tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / Det;
                    tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / Det;
                    tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / Det;
                    tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / Det;
                    tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / Det;
                    tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / Det;
                    tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / Det;
                    tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / Det;
                    return tmp;
                }
            }
        }
        else
            cout << "the operation is not valid " << endl;
    }

    Matrix transposition()
    {
        swap(m_m, m_n);
        Matrix tmp(m_n, m_m);
        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                tmp.m_mat[i][j] = m_mat[j][i];
            }
        }

        return tmp;

    }

    int Rang()
    {
        int rang = 0;
        int k = 0;
        int l = 0;
        int g = 0;

        double det = DET();

        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                if (m_mat[i][j] == 0)
                {
                    k++;
                }
            }
        }
        if (k == m_m * m_n)
        {
            rang = 0;
        }
        else
        {
            if (((m_n = 1) && (m_m != 1)) || ((m_m = 1) && (m_n != 1)) || (m_n = 1) && (m_m = 1))
            {
                rang = 1;
            }

            if ((m_n = m_m) && (m_n == 2))
            {
                if (det == 0)
                {
                    rang = 1;
                }
                else
                {
                    rang = 2;
                }
            }

            if ((m_n = m_m) && (m_n == 3))
            {

                g = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
                if (g == 0)
                {
                    rang = 1;
                }
                else
                {
                    l = det;
                    if (l == 0)
                    {
                        rang = 2;
                    }
                    else
                    {
                        rang = 3;
                    }
                }
            }
        }
        return rang;
    }

    void linear_dependence()
    {
        double det = 0;
        det = DET();
        if (det == 0)
        {
            cout << "dependent vectors" << endl;
        }
        else
        {
            cout << "not dependent vectors" << endl;
        }

    }

    Matrix operator%(const Matrix& mat)
    {
        const double eps = 0.00001;
        double max = 0;
        int index;
        int k = 0;
        double* x = new double[m_n];

        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                cout << m_mat[i][j] << "*x" << j;
                if (j < m_m - 1)
                   cout << " + ";
            }
            cout << " = " << mat.m_mat[i][0] << endl;
        }

        while (k < m_n)
        {
            max = abs(m_mat[k][k]);
            index = k;
            for (int i = k + 1; i < m_n - 1; i++)
            {
                if (abs(m_mat[i][k]) > max)
                {
                    max = abs(m_mat[i][k]);
                    index = i;
                }
            }
            if (max < eps)
            {
                cout << "The solution cannot be obtained because of zero values " << endl;
                return *this;
            }

            for (int j = 0; j < m_n; j++)
            {
                double temp = m_mat[k][j];
                m_mat[k][j] = m_mat[index][j];
                m_mat[index][j] = temp;
            }

            for (int i = k; i < m_n; i++)
            {
                double temp = m_mat[i][k];
                if (abs(temp) < eps)
                    continue;
                for (int j = 0; j < m_n; j++)
                    m_mat[i][j] = m_mat[i][j] / temp;
                mat.m_mat[i][0] = mat.m_mat[i][0] / temp;
                if (i == k)
                    continue;
                for (int j = 0; j < m_n; j++)
                    m_mat[i][j] = m_mat[i][j] - m_mat[k][j];
                mat.m_mat[i][0] = mat.m_mat[i][0] - mat.m_mat[k][0];
            }
            k++;
        }
        for (k = m_n - 1; k >= 0; k--)
        {
            x[k] = mat.m_mat[k][0];
            for (int i = 0; i < k; i++)
                mat.m_mat[i][0] = mat.m_mat[i][0] - m_mat[i][k] * x[k];
        }
        for (int i = 0; i < m_n; i++)
            cout << "x" << i << " = " << x[i] << endl;
        return *this;
    }

    friend istream& operator>>(istream& in, Matrix& mat);
    friend ostream& operator<<(ostream& out, const Matrix& mat);
private:
    int m_n, m_m;
    double** m_mat;
};

istream& operator>>(istream& in, Matrix& mat)
{
    for (int i = 0; i < mat.m_n; i++)
    {
        for (int j = 0; j < mat.m_m; j++)
        {
            in >> mat.m_mat[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& mat)
{

    for (int i = 0; i < mat.m_n; i++)
    {
        for (int j = 0; j < mat.m_m; j++)
        {
            out << mat.m_mat[i][j] << " ";
        }
        out << endl;
    }
    return out;
}