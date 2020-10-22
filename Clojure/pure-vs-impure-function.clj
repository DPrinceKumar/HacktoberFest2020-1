;; pure function 
;; It's return value is the same for the same arguments
;; pure functions cannot access anything other than what they are passed
;; An expression is said to be pure if its evaluation lacks side-effects
 
;; When a function performs any other “action”, apart from calculating its return value, the function is impure.

;; Pure Function
(defn calculate-area
  [radius]
  (* 3.14 (* radius radius)) )
  
;; Impure function 
(defn foo 
  [num]
  (+ num (rand-int 50))) 

;; pure fucntion 
;; don't modify argument being passed to them
;; It's evaluation has no side effects
;; never alter state/ does not modify external variable
;; no use of global variables 
(defn pure-foo 
  [x y]
  (+ (* x x) (* y y)))
  
;; Impure function 
(def x 2)
(defn impure-foo
  [y]
  (+ (* x x) (* y y)))


;; Pure functions can always be parallelized. Distribute the input values over a number of threads, and collect the results.

;; Memoization
;; Because pure functions are referentially transparent, we only need to compute their output once for given inputs.
;; Caching and reusing the result of a computation is called memoization, and can only be done safely with pure functions.

;; Laziness
;; A variation on the same theme. We only ever need to compute the result of a pure function once,
;; but what if we can avoid the computation entirely? Invoking a pure function means you specify a dependency:
;; this output value depends on these input values. But what if you never use the output value? Because the function 
;; can not cause side effects, it does not matter if it is called or not. Hence a smart system can be lazy and optimize 
;; the call away.
;; Some languages, like Haskell, are completely built on lazy evaluation. Only values that are needed to
;; achieve side effects are computed, the rest is ignored. Ruby’s evaluation strategy is called strict evaluation,
;; each expression is completely evaluated before its result can be used in another expression
