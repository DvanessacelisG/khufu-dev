FROM node:10.15.1
COPY package.json /app/package.json
RUN npm install -g bs-platform --unsafe-perm && apt-get update && apt-get install cron -y
WORKDIR /app
RUN npm install
EXPOSE 8001
