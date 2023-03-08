class Solution(object):
    def mostPopularCreator(self, creators, ids, views):
        """
        :type creators: List[str]
        :type ids: List[str]
        :type views: List[int]
        :rtype: List[List[str]]
        """

        n = len(creators)

        score = {}
        vid = {}

        best = 0

        for i in range(n):
            k = creators[i]
            curr_id = ids[i]
            v = int(views[i])

            if k not in score:
                score[k] = v
                vid[k] = (v, curr_id)
            else:
                score[k] += v

                prev_v = vid[k]
                if v > prev_v[0] or (v == prev_v[0] and curr_id < prev_v[1]):
                    vid[k] = (v, curr_id)

            best = max(best, score[k])

        ret = []
        for k in score:
            if score[k] == best:
                ret.append([k, vid[k][1]])

        return ret