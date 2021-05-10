import numpy

p = 1.0
x = numpy.arange(1.0, 7.0, 1.0)
y = [0.571, 0.889, 1.091, 1.231, 1.333, 1.412]
h = 1.0


def center() -> list[float]:
    return [None if (i == 0 or i == len(y) - 1) else (y[i + 1] - y[i - 1]) / 2 * h for i in range(len(y))]


def left() -> list[float]:
    return [None if (i == 0 or i == len(y) - 1) else
            (y[i + 1] - y[i - 1]) / 2 * h for i in range(len(y))]


def isNan(val: float):
    return 0 if val is None else val


def leftInter(_y: float, _yl: float, _h: float) -> float:
    return (_y - _yl) / _h


def secondRunge() -> list[float]:
    y2h = [0.0 if i < 2 else (y[i] - y[i - 2]) / (2 * h) for i in range(len(y))]
    yh = left()
    return [None if i < 2 else
            isNan(yh[i]) + (isNan(yh[i]) - isNan(y2h[i])) / (2.0 ** p - 1)
            for i in range(len(y))]


def alignCoeffs() -> list[float]:
    return [None if i == len(y) - 1 else
            y[i] * y[i] / x[i] / x[i] * leftInter(
                -1. / y[i + 1], -1. / y[i],
                -1. / x[i + 1] - -1. / x[i]
            ) for i in range(len(y))]


def secondLeft() -> list[float]:
    return [None if i == 0 or i == len(y) - 1 else
            (y[i - 1] - 2 * y[i] + y[i + 1]) / (h * h)
            for i in range(len(y))]


def startMsg(msg: str, init_list: list[float]):
    print(msg)
    [print("{:7.4} ".format(i if i is not None else "Nan")) for i in init_list]
    print()


def showResult(msg: str, result: list[float]):
    print(msg.capitalize())
    [print("{:7.4} ".format(i if i is not None else "Nan")) for i in result]
    print()


def wrapper() -> None:
    startMsg("X\t\t:", x)
    startMsg("Y\t\t:", y)

    for fn in [left, center, secondRunge, alignCoeffs, secondLeft]:
        showResult(fn.__name__, fn())




