import redis

# 创建Redis连接对象
r = redis.Redis(host='localhost', port=6379, db=0)

r.set('mykey', 'Hello Redis!')
value = r.get('mykey')
print(f'The value of "mykey" is: {value.decode("utf-8") if value else "Not Found"}')

r.lpush('mylist', 'item1')
r.lpush('mylist', 'item2')
# 获取列表中的所有元素
mylist = r.lrange('mylist', 0, -1)
print(f'The items in "mylist" are: {mylist}')
# 从列表的右侧移除一个元素并返回它
rightmost_item = r.rpop('mylist')
print(f'The rightmost item in "mylist" is: {rightmost_item.decode("utf-8") if rightmost_item else "Empty"}')

# 集合数据操作
# 添加元素到集合
r.sadd('myset', 'member1')
r.sadd('myset', 'member2', 'member3')
# 获取集合中的所有元素
myset = r.smembers('myset')
print(f'The members in "myset" are: {myset}')
# 移除集合中的一个元素
r.srem('myset', 'member2')
# 再次获取集合中的所有元素
myset_after_remove = r.smembers('myset')
print(f'The members in "myset" after removing "member2" are: {myset_after_remove}')