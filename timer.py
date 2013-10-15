from timeit import Timer

orig_t = Timer("""orig.iterator(1000,4)""", setup="""import orig""")
print "Time to complete original " + str(orig_t.timeit(5))

orig_t = Timer("""orig_c.iterator_c_call(1000,4)""", setup="""import orig_c""")
print "Time to complete c ext version " + str(orig_t.timeit(5))

