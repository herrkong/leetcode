# leetcode_mysql_175

## 1 description

```
组合两个表

编写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：
FirstName, LastName, City, State

# create table Person( PersonId int(11) NOT NULL default 0 primary key, FirstName varchar(20), LastName varchar(20));

#create table Address ( AddressId int(11) not null default 0 primary key, PersonId int(11) not null default 0 , City varchar(20), State varchar(20) );

```

```
数据库在通过连接两张或多张表来返回记录时，都会生成一张中间的临时表，然后再将这张临时表返回给用户。 在使用left jion时，on和where条件的区别如下：

1、on条件是在生成临时表时使用的条件，它不管on中的条件是否为真，都会返回左边表中的记录。

2、where条件是在临时表生成好后，再对临时表进行过滤的条件。这时已经没有left join的含义（必须返回左边表的记录）了，条件不为真的就全部过滤掉。
```

![1576999833653](C:\Users\hkong\AppData\Roaming\Typora\typora-user-images\1576999833653.png)

## 2 left join 

```
select p.FirstName,p.LastName,a.City,a.State  from  Person p left join Address a on  p.PersonId = a. PersonId;
```

```
Insert into Person (PersonId ,FirstName,LastName ) values (10001,"darwin","kong");

 Insert into Person (PersonId ,FirstName,LastName ) values (10002,"winkey","li");

```



![1577000785487](C:\Users\hkong\AppData\Roaming\Typora\typora-user-images\1577000785487.png)

## 3

![1577000407611](C:\Users\hkong\AppData\Roaming\Typora\typora-user-images\1577000407611.png)