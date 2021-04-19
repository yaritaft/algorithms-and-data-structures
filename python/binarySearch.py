def binary_search(mylist, elem):
    low = 0
    high = len(mylist)-1
    counter = 0
    while low < high:
        counter = counter + 1
        print(counter)
        mid = (high  + low) // 2
        guess = mylist[mid]
        print("my guess ", guess)
        if guess == elem:
            return
        elif guess < elem:
            low = mid + 1
        elif guess > elem:
            high = mid - 1

binary_search([1,2,3,4,5,6,7,8,9,10,11,15,22,44,55,77,88,99], 4)