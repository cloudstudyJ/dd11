#This code computes a maximum profit value...
import sys

def maxProfit_bruteforce (prices):
   max_price = -sys.maximum
    for i, price in enumerate(prices):
        for j in range(i, len(prices)):
            max_price = max(prices[j] - price, max_price)

    return max_price
