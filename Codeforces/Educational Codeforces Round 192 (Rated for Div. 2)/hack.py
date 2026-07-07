def generate_hack_testcase():
    t = 1
    n = 5000
    m = 5000
    a = "0" * n
    b = "0" * m
    with open("hack_test.txt", "w") as f:
        f.write(f"{t}\n")
        f.write(f"{a}\n")
        f.write(f"{b}\n")
if __name__ == "__main__":
    generate_hack_testcase()