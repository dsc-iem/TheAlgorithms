def knapsack(objects, profits, weights, capacity):
    value = dict()
    for i in range(len(objects)):
        value[i] = profits[i]/weights[i]
    result = []
    while sum(result) <= capacity:
        object_chosen = max(value.values())
        key = list(value.values()).index(object_chosen)
        result.append(weights[key])
        value[key] = 0
        
    if sum(result) > 15:
        last = result[-1]
        num_req = sum(result) - 15
        last = last - num_req
        result.pop()
        result.append(last)

    final_profit = 0
    for indice in range(len(result)):
        final_profit += profits[weights.index(result[indice])]
    return result, final_profit


print(knapsack([0, 1, 2, 3, 4], [2, 4, 10, 7, 8], [3, 4, 1, 5, 6], 15))



