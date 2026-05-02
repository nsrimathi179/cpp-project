#include <iostream>
#include <memory>
using namespace std;

class Expr {
public:
    virtual double evaluate() = 0;
    virtual void print() = 0;
    virtual ~Expr() {}
};

class Literal : public Expr {
private:
    double value;

public:
    Literal(double v) : value(v) {}

    double evaluate() override {
        return value;
    }

    void print() override {
        cout << value;
    }
};

class UnaryExpr : public Expr {
private:
    char op;
    shared_ptr<Expr> operand;

public:
    UnaryExpr(char o, shared_ptr<Expr> e) : op(o), operand(e) {}

    double evaluate() override {
        if (op == '-') return -operand->evaluate();
        return operand->evaluate();
    }

    void print() override {
        cout << op << "(";
        operand->print();
        cout << ")";
    }
};

class BinaryExpr : public Expr {
private:
    char op;
    shared_ptr<Expr> left;
    shared_ptr<Expr> right;

public:
    BinaryExpr(char o, shared_ptr<Expr> l, shared_ptr<Expr> r)
        : op(o), left(l), right(r) {}

    double evaluate() override {
        switch (op) {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
        }
        return 0;
    }

    void print() override {
        cout << "(";
        left->print();
        cout << " " << op << " ";
        right->print();
        cout << ")";
    }
};

int main() {
    auto five = make_shared<Literal>(5);
    auto three = make_shared<Literal>(3);
    auto two = make_shared<Literal>(2);

    auto sum = make_shared<BinaryExpr>('+', five, three);
    auto product = make_shared<BinaryExpr>('*', sum, two);
    auto negated = make_shared<UnaryExpr>('-', three);
    auto final_expr = make_shared<BinaryExpr>('+', product, negated);

    cout << "Expression: ";
    final_expr->print();
    cout << endl;
    cout << "Result: " << final_expr->evaluate() << endl;
    return 0;
}
