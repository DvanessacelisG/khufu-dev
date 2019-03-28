FROM node:10.15.1
COPY package.json /app/package.json
RUN npm install -g bs-platform --unsafe-perm
WORKDIR /app
RUN npm install
EXPOSE 8001
COPY . ./
RUN npm run build
CMD ["npm","run","server"]
