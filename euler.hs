module Euler where

import Data.Array as Array
import Data.Char as Char
import Data.Set  as Set
import Data.List as List

fib = 1 : 1 : zipWith (+) fib (tail fib)

euler2 = sum [x | x <- takeWhile (<4000000) fib, even x]

primeFactors   :: Integer -> [Integer]
primeFactors n = factor n primes

factor :: Integer -> [Integer] -> [Integer]
factor _ []		   = []
factor n (x:xs)
  | x^2 > n		   = [n]
  | n `mod` x == 0 = x : factor (n `div` x) (x:xs)
  | otherwise	   = factor n xs

primes :: [Integer]
primes = 2 : Prelude.filter ((==1) . length . primeFactors) [3,5..]

euler3 = last $ primeFactors 600851475143

euler5 = List.foldr lcm 1 [1..20]

euler7 = primes !! 10000

triplet   :: Integer -> [[Integer]]
triplet s = [ [a,b,c] | n <- [1..floor . sqrt . fromIntegral $ s],
						m <- [succ n..floor . sqrt . fromIntegral $ s], 
						let a = m^2 - n^2,
						let b = 2*m*n,
						let c = m^2 + n^2,
						sum [a,b,c] == s]

euler9 = product . head . triplet $ 1000

euler10 = sum [x | x <- takeWhile (<2000000) primes]

coins = [1,2,5,10,20,50,100,200] -- coin denominations

countWays	  :: Int -> Int -> Int
countWays 1 _ = 1
countWays n x = sum $ Prelude.map sumCoins [0 .. x `div` coins !! pred n]
  where sumCoins c = countWays (pred n) (x - c * coins !! pred n)

euler31 = countWays (length coins) 200

pentas = let
	isPenta = (`member` Set.fromList penta)
	penta	= [(x*(3*x-1)) `div` 2 | x <- [1..5000]]
  in [a-b | a <- penta, b <- takeWhile (<a) penta, isPenta (a-b), isPenta(a+b)]

euler44 = head pentas

same x y = (show x) List.\\ (show y) == []

check n = all (same n) $ List.map (n*) [2..6]

euler52 = head $ List.filter check [1..]
