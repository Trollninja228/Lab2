var a=4;
console.log(typeof(a));
a="Hello";
console.log(typeof(a));
console.log(2=="2");
console.log(2==="2");
a=10101010
var b={
    'id':'some id',
    'name':'Me',
    department: 'Site',
    age: a
}
console.log(b);
c=[1,2,3,4,5];
console.log(c);
c.push(10);
console.log(c);
c.pop();
console.log(c);
a=3;
b=a;
a=10
console.log(b,a);

a=c;
c.push(20);
console.log(a,c);

function my_func(){
    return 0;
}
console.log(my_func());

for(var i=0;i<10;i++){
    console.log(i);
}

console.log(i);


for(const num of c){
    console.log(num);
}

c.forEach(function(num){ //anonumous func
    console.log(num);
})
console.log(c); 
c.sort();
c.push(10)
console.log(c); 

console.log(c.find((number)=>number>3));

// var newArr=c.map((num,index)) => num*index);
console.log(newArr);
console.log(c.slice(3,5));
console.log(c)

var newArr=c.slice(3,3,20,30,40);//start, delete count, items
console.log(newArr);

var b={
    'id':'some id',
    'name':'Me',
    age: a,
    'department':{
        name:'Site',
        origin:'Main'
    }
}

console.log(b);

var jsonString= JSON.stringify(b);
console.log(jsonString);

el_id=document.getElementById('birthday');
console.log(el_id);
console.log(el_id.innertext);

el_cl=document.getElementsByClassName('class');
p=el_cl.item(0);
p.style.color='blue'

newPar=document.createElement('p');
newPar.innerText="New Paragraph";
newPar.style.fontsize="20px"
newPar.style.color='green';

cont=document.getElementById('cont');
cont.appendChild(newPar);


alert("hi");
confirm("confirm?");

function myClick(){
    alert("you clicked!!!!");
}

newPar.addEventListener("click",myClick);
newPar.onclick(myClick);

// newPar.innerHTML=<p>Test!</p>