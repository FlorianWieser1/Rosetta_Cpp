import numpy
import matplotlib.pyplot

data = numpy.loadtxt(fname='data.csv', delimiter=';')
print(data[:,0])
print(data[:,1])
matplotlib.pyplot.plot(data[:,0], data[:,1],"k", data[:,0], data[:,1],"ok")
matplotlib.pyplot.ylabel('time [sec]')
matplotlib.pyplot.xlabel('which')
matplotlib.pyplot.title('processing time = f(which)')
matplotlib.pyplot.savefig("hw5_Wieser.png")
