class Solution(object):
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        aA = arriveAlice.split("-")
        am = int(aA[0])
        ad = int(aA[1])
        temp1 = 0
        for i in range(0, am - 1):
            temp1 += months[i]
        temp1 += ad

        lA = leaveAlice.split("-")
        lm = int(lA[0])
        ld = int(lA[1])
        temp2 = 0
        for i in range(0, lm - 1):
            temp2 += months[i]
        temp2 += ld

        aB = arriveBob.split("-")
        am1 = int(aB[0])
        ad1 = int(aB[1])
        temp3 = 0
        for i in range(0, am1 - 1):
            temp3 += months[i]
        temp3 += ad1

        lB = leaveBob.split("-")
        lm1 = int(lB[0])
        ld1 = int(lB[1])
        temp4 = 0
        for i in range(0, lm1 - 1):
            temp4 += months[i]
        temp4 += ld1

        mi1 = max(temp1, temp3)
        mi2 = min(temp2, temp4)

        if mi1 > mi2:
            return 0
        else:
            return mi2 - mi1 + 1