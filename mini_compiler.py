# mini_compiler.py

import re

# ====== LEXER ======
def tokenize(code):
    tokens = re.findall(r'\d+|[A-Za-z_]\w*|==|!=|<=|>=|[+\-*/=()<>:]|.', code)
    return tokens

# ====== PARSER ======
class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0

    def peek(self):
        return self.tokens[self.pos] if self.pos < len(self.tokens) else None

    def eat(self, val=None):
        tok = self.peek()
        if val and tok != val:
            raise SyntaxError(f"Expected '{val}', got '{tok}'")
        self.pos += 1
        return tok

    def parse(self):
        stmts = []
        while self.peek():
            stmts.append(self.statement())
        return stmts

    def statement(self):
        if re.match(r'[A-Za-z_]\w*', self.peek()) and self.tokens[self.pos+1] == "=":
            var = self.eat()
            self.eat("=")
            expr = self.expr()
            return ("assign", var, expr)
        elif self.peek() == "print":
            self.eat("print")
            self.eat("(")
            expr = self.expr()
            self.eat(")")
            return ("print", expr)
        else:
            raise SyntaxError("Invalid statement: " + self.peek())

    def expr(self):
        left = self.term()
        while self.peek() in ("+", "-"):
            op = self.eat()
            right = self.term()
            left = (op, left, right)
        return left

    def term(self):
        left = self.factor()
        while self.peek() in ("*", "/"):
            op = self.eat()
            right = self.factor()
            left = (op, left, right)
        return left

    def factor(self):
        tok = self.peek()
        if re.match(r'\d+', tok):
            self.eat()
            return ("num", int(tok))
        elif re.match(r'[A-Za-z_]\w*', tok):
            self.eat()
            return ("var", tok)
        elif tok == "(":
            self.eat("(")
            e = self.expr()
            self.eat(")")
            return e
        else:
            raise SyntaxError("Invalid factor: " + tok)

# ====== COMPILER ======
def compile_ast(ast):
    bytecode = []
    for stmt in ast:
        if stmt[0] == "assign":
            _, var, expr = stmt
            gen_expr(expr, bytecode)
            bytecode.append(("STORE", var))
        elif stmt[0] == "print":
            _, expr = stmt
            gen_expr(expr, bytecode)
            bytecode.append(("PRINT",))
    return bytecode

def gen_expr(expr, code):
    if expr[0] == "num":
        code.append(("PUSH", expr[1]))
    elif expr[0] == "var":
        code.append(("LOAD", expr[1]))
    elif expr[0] in ("+", "-", "*", "/"):
        gen_expr(expr[1], code)
        gen_expr(expr[2], code)
        code.append((expr[0].upper(),))
    else:
        raise RuntimeError("Unknown expr: " + str(expr))

# ====== VIRTUAL MACHINE ======
def run(bytecode):
    stack = []
    vars_ = {}
    for instr in bytecode:
        op = instr[0]
        if op == "PUSH":
            stack.append(instr[1])
        elif op == "LOAD":
            stack.append(vars_.get(instr[1], 0))
        elif op == "STORE":
            vars_[instr[1]] = stack.pop()
        elif op == "PRINT":
            print(stack.pop())
        elif op == "+":
            b,a = stack.pop(), stack.pop(); stack.append(a+b)
        elif op == "-":
            b,a = stack.pop(), stack.pop(); stack.append(a-b)
        elif op == "*":
            b,a = stack.pop(), stack.pop(); stack.append(a*b)
        elif op == "/":
            b,a = stack.pop(), stack.pop(); stack.append(a//b)
        elif op == "ADD":
            b,a = stack.pop(), stack.pop(); stack.append(a+b)
        elif op == "SUB":
            b,a = stack.pop(), stack.pop(); stack.append(a-b)
        elif op == "MUL":
            b,a = stack.pop(), stack.pop(); stack.append(a*b)
        elif op == "DIV":
            b,a = stack.pop(), stack.pop(); stack.append(a//b)
    return vars_

# ====== TEST ======
if __name__ == "__main__":
    code = """
x = 5
y = 10
z = x + y * 2
print(z)
"""
    tokens = tokenize(code)
    parser = Parser(tokens)
    ast = parser.parse()
    bytecode = compile_ast(ast)
    run(bytecode)
from jumble import jumble  # type: ignore
import choo as choose  # type: ignore
