(AST_FUNC (int() main)(AST_COMPOUND (AST_DECL (= (int i) 0))(AST_DECL (= (int sum) 0))(AST_FOR (INIT (= i 100))(COND i)(STEP (= i (- (i 1))))(BODY (= sum (+ sum i))))(AST_RETURN sum)))
