## Securely connect to XXX
```
openssl s_client -connect www.baidu.com:443
```
## Show a Certificate
```
openssl x509 -in baidu.pem
openssl x509 -in baidu.pem -text -noout
```



## Key Operations
- RSA
  - key gen
  ```
    openssl genrsa -out rsa.key 2048
  ```
- DSA
  - key gen
  ```
    openssl dsaparam -genkey 2048 | openssl dsa -out dsa.key 
  ```

- ECDSA
  - key gen
  ```
  openssl ecparam -genkey -name secp256r1 | openssl ec -out ec.key
  ```

- Show key
  ```
  openssl rsa -text -in rsa.key 
  ```
  
- Extract key
  ```
  openssl rsa -in rsa.key -pubout -out rsa-public.key
  ```
  
## CSR
- Create
  ```
  openssl req -new -key rsa.key out rsa.csr
  ``` 
- Show
  ```
  openssl req -text -in rsa.csr -noout
  ```
  
## Signing
```
openssl x509 -req -days 365 -in rsa.csr -signkey rsa.key -out rsa.crt
```

## Convertion
- PEM to DER
  ```
  openssl x509 -inform PEM -in **.pem -outform DER -out **.der
  ```
- DER to PEM
  ```
  openssl x509 -inform DER -in **.der -outform PEM -out **.pem
  ```






